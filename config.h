#include <time.h>
#ifndef freopenr
#define freopenr freopen("/home/mika/Code/ACM/并查集/input.txt","r",stdin)
#endif
#ifndef freopenw
#define freopenw freopen("/home/mika/Code/ACM/并查集/output.txt","w",stdout)
#endif
#define timeb time_t start_time = clock()
#define timee time_t end_time = clock()
#define timep cout<<"程序段运行时间：" << static_cast<double> (end_time - start_time) / CLOCKS_PER_SEC  << "s" << endl