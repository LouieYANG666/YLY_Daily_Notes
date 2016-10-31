/* 2016.10.31 */
/* from Dijkstra Algorithmn */

// 1. 定义int32_t的最大有效值
#define INF         (~(0x1 << 31))   

// 2. 判断a是否是英文字母
#define isLetter(a)     ((((a)>='a')&&((a)<='z')) || (((a)>='A') && ((a)<='Z')))  

// 3. 计算数组a的长度
#define LENGTH(a)      (sizeof(a)/sizeof(a[0]))
