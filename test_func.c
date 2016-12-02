#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef	struct _tag_dsp_stat_info{
		unsigned int	node_type;
			unsigned int    resource_alloc_info[20];
				unsigned int	rsv[11];
}dsp_stat_info;


dsp_stat_info g_stat_info;

dsp_stat_info *p_dsp_stat = &g_stat_info;

char g_node_type = 1;
int g_factory_id = 11;
char g_config_mode = 0;

#define MESH_MAXSUBFRAME_NUM 20
#define CONFIG_0 0
#define CONFIG_2 2

int dsp_res_alloc_set(unsigned int *val, char tti_num)
{
	
	int i;
	int ret = -1;

	if(tti_num != 20)
	{
		printf("tti num is not correct in dsp_res_alloc_set\n");
		return -1;
	}
	
	if(val)
	{
		for(i=0; i<tti_num; i++)
		{
			p_dsp_stat->resource_alloc_info[i] = val[i];
		}
		ret = 0;
	}

	return ret;
}

int main()
{
	int32_t flag;
	int32_t i = 0;
	uint32_t config_0_master[MESH_MAXSUBFRAME_NUM] = {1,0, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 1,1, 0,1};
	uint32_t config_0_slaver[MESH_MAXSUBFRAME_NUM] = {0,1, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 1,1};
	uint32_t config_2_master[MESH_MAXSUBFRAME_NUM] = {1,0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,0, 1,1};
	uint32_t config_2_slaver[MESH_MAXSUBFRAME_NUM] = {0,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1, 0,1};
	uint32_t *p_my_config = NULL;
	
	if(g_node_type == 0)  //master
	{
		switch(g_config_mode)
		{
			case CONFIG_0:
				p_my_config = config_0_master;
				break;
			case CONFIG_2:
				p_my_config = config_2_master;
				break;
			default:
				//rrc_log_trace(LL_ERROR, "wrong config mode");
				return -1;
		}
	}
	else  //slaver
	{
		switch(g_config_mode)
		{
			case CONFIG_0:
				p_my_config = config_0_slaver;
				break;
			case CONFIG_2:
				p_my_config = config_2_slaver;
				break;
			default:
				//rrc_log_trace(LL_ERROR, "wrong config mode");
				return -1;
		}
	}
	
	flag = dsp_res_alloc_set(p_my_config, 20);
	
	if(-1 == flag)
	{
		//rrc_log_trace(LL_ERROR, "dsp_res_alloc_set error");
		return -1;
	}

	for(i=0; i<20; i++)
	{
		printf("%5d\n", g_stat_info.resource_alloc_info[i]);
	}

	return 0;

}
