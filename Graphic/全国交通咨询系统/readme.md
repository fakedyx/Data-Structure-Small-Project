#  **问题重述**

处于不同目的的旅客对交通工具有不同的要求。例如，因公出差的旅客希望在旅途中的时间尽可能地短，出门旅游的游客则期望旅费尽可能省，而老年旅客则要求中转次数最少。编制一个全国城市间的交通咨询程序，为旅客提供两种或三种最优决策的交通咨询。

**目标：**

1. 提供对城市信息进行编辑（如添加或删除）的功能。

(2)城市之间有两种交通工具：火车和飞机。提供对列车时刻表和飞机航班进行编辑（增设或删除）的功能。

(3)提供两种最优决策：最快到达和最省钱到达。全程只考虑一种交通工具。

(4)旅途中耗费的总时间应该包括中转站的等候时间。

(5)咨询以用户和计算机的对话方式进行。由用户输入起始站、终点站、最优决策原则和交通工具。输出信息：最快需要多长时间才能到达或者最少需要多少旅费才能到达，并详细说明依次于何时乘坐哪一趟列车或哪一次班机到何地。

(6)对全国城市交通图和列车时刻表及飞机航班表进行编辑，应该提供文件形式输入和键盘输入两种方式。飞机航班表的信息应包括：起始站的出发时间、终点站的到达时间和票价；列车时刻表则需根据交通图给出各个路段的详细信息，例如：对从北京到上海的火车，需给出北京至天津、天津至徐州及徐州至上海各段的出发时间、到达时间及票价等信息。

 (7)以邻接表作交通图的存储结构，表示边的结构内除含有邻接点的信息外，还应包括交通工具、路程中耗费的时间和花费以及出发和到达的时间等多种属性。

 (8)*可考虑增加旅途中转次数最少的最优决策。

# **分析过程**

1. 全国交通图中数据量较多，顶点为城市，而边上的信息非常丰富，包括两城市间的路程，两种交通工具的发车时间，费用，交通工具的车牌号或者航班号等信息。
2. 首先将咨询者分为两类，管理员和用户，管理员可以对交通图进行编辑，而用户只能进行查询，所以设置不同的界面，界面里面包括不同的功能。

主界面

![img](https://img-blog.csdnimg.cn/6ecb40cae4214c4fac4326cabb9a7a11.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



管理员界面

![img](https://img-blog.csdnimg.cn/938c0a5b70fb4c24847902d26e95e66d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



用户界面

![img](https://img-blog.csdnimg.cn/6e6ae66c40aa44daab6e8941fbbac082.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



1. 对管理员界面分析:

1. 创建交通网络图：通过从外部文本文件中导入信息然后用邻接表存储，创建完成交通网络图。包含两个文件，一个导入城市，一个导入边上的信息。（下面展示部分数据）

![img](https://img-blog.csdnimg.cn/c66dc0b6c75a44a69d45e2e5315390b4.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_18,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



![img](https://img-blog.csdnimg.cn/71492ecdca3d4029b96c1081253f5e49.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



（数据说明:出发城市号 目的城市号 距离 费用 一天内有几趟车 第一趟车的出发时间（655表示6:55）第一趟车的车牌号 第二趟…）

（航班表未进行展示）

2）增添城市：在存储城市节点的数组中添加新城市即可。

3）删除城市：删除一个城市同时要删除与它相关的边，时间复杂度为O（V+E）。

4）增添指定路线:找到要出发点节点，然后遍历其邻接表，找到相应位置，修改里面的数据，但是作者的火车，飞机出发时间都是有序的，所以还需要再进行一次遍历，插入到出发时间链表的相应位置。时间复杂度与出发节点后的链表长度和时间信息链表相关。

5）删除指定路线:找到要删除路线的起始城市，然后遍历其后的链表，找到相应的表节点，然后进行删除即可。时间复杂度与起始节点后的链表长度有关，最坏为O（V）。

6）查看所有的火车和航班：遍历整个表，时间复杂度为O（V+E），但是实际时间还要加上遍历每条边上存储的时间链的时间。

（展示部分）

![img](https://img-blog.csdnimg.cn/4045117527874cd0a0987df2e5933378.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



1. 用户界面分析：旅客出行出于不同目的：提供了“距离最短”，“费用最少”和“转站最少”3种选项，让乘客可以选择适合自己的路径；这里作者全部采用了Floyd算法，没有使用Dijkstra算法，因为在用户界面，只能进行查询操作，不能进行编辑，所以在用户进行第一次加载交通图时，直接进行Floyd算法，将所有点的最短路径等信息全部保存在Path和dis数组中，后面不用重复Floyd，只用通过Path和dis数组查询即可以。而Dijkstra每次查询都要运行，不具有存储功能。Floyd算法的时间复杂度为O（n^3），空间复杂度为O（n^2）.

1. 距离最短：对于所带“路径长度”的权值采用floyd算法，计算最短路径也就是最短时间的乘车方案；因为floyd算法可以把各个顶点之间的最低路径得到，要要查询哪两个点，直接通过dis和Path数组，便可以直接获得所要求两点的最低路径。
2. 费用最少：思路同求最短路径一致，只是将权值换成费用即可。
3. 转站最少：换一个思维，假设在所有边上加上同一个权值—1，然后依据此权值同样进行Floyd算法，就可以求得中转次数最少的方案。 当然，作者还使用修改过DFS算法，也可以完成了这一功能。DFS时间复杂度为O（V+E），空间复杂度也为O（V）。

用DFS解决中转次数--具体代码如下:

```cpp
1.	void DFS(ALGraph G,int u)
2.	{
3.	    //d[i]表示从u到i节点的最短路径
4.	    for (int i = 0; i < G.vexnum; ++i)
5.	    {
6.	        d[i] = INF; //初始化长度
7.	    }
8.	    visited[u] = TRUE;
9.	    d[u] = 0;
10.	    EnQueue(Q, u);
11.	    while (!IsEmpty(Q)) {
12.	        DeQueue(Q, u);
13.	        for (w = FirstNeighour(G, u); w >= 0; w = NextNeighbor(G, u, w))
14.	        {
15.	            if (!visited[w])
16.	            {
17.	                visited[w] = TRUE;
18.	                d[w] = d[u] + 1;    //中转站加1
19.	                EnQueue(Q, w);   
20.	            }
21.	        }//if
22.	    }//while
23.	}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

# **测试**

1. 管理员主界面：

![img](https://img-blog.csdnimg.cn/11ec17c243a14ae6832dc25eebe20419.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



1. 用户主界面：

![img](https://img-blog.csdnimg.cn/2e10ebfcf5364d54a151653fa7fa7a9b.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



1. 初始化交通图和列车时刻表：

![img](https://img-blog.csdnimg.cn/addad4cecd5c44af845c081d9716447f.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



1. 查看已有的城市：

![img](https://img-blog.csdnimg.cn/f0507e4ca55b4e8f96f976d74a5f6fbb.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑



1. 增添城市和路径：

![img](https://img-blog.csdnimg.cn/111566d954ae4ba4998fc9dfc578057c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑

1. 删除城市和路径：

![img](https://img-blog.csdnimg.cn/d5bd11c2aa2441709358e281b786c67e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑               ![img](https://img-blog.csdnimg.cn/bfd62da679a04b9789b0a79f17d07075.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑

![img](https://img-blog.csdnimg.cn/0910055923a74bcb8f203d518a47ad54.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_13,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑![img](https://img-blog.csdnimg.cn/3e99cfe2397b4f14ace5fa7c2dc0f707.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_13,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑

1. 最快到达：

![img](https://img-blog.csdnimg.cn/5ceb42af417648d4bed6078a16a82745.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBAWEpUVS1GYWtl,size_20,color_FFFFFF,t_70,g_se,x_16)![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)编辑

1. 最省钱到达：略
2. 转站最少：略



# **源代码**

```cpp
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<memory.h>

#define MAXCITYNUM 20        //定义城市数量

//交通工具速度
#define train_speed 400.0
#define plane_speed 800.0

//状态变量
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#define  DataType int

#define MAX_NAME 10 /* 顶点字符串的最大长度 */
#define MAX_INFO 10 /* 相关信息字符串的最大长度 */

#define MAXV 100
#define INF 10000

#define VexNum 5

int t_distance_Path[MAXCITYNUM][MAXCITYNUM];
int p_distance_Path[MAXCITYNUM][MAXCITYNUM];
int t_price_Path[MAXCITYNUM][MAXCITYNUM];
int p_price_Path[MAXCITYNUM][MAXCITYNUM];
int t_distance_dis[MAXCITYNUM][MAXCITYNUM];
int p_distance_dis[MAXCITYNUM][MAXCITYNUM];
int t_price_dis[MAXCITYNUM][MAXCITYNUM];
int p_price_dis[MAXCITYNUM][MAXCITYNUM];

int t_transfer_Path[MAXCITYNUM][MAXCITYNUM];
int p_transfer_Path[MAXCITYNUM][MAXCITYNUM];
int t_transfer_dis[MAXCITYNUM][MAXCITYNUM];
int p_transfer_dis[MAXCITYNUM][MAXCITYNUM];

//全局变量用来计算价格,路程,中转次数
int s_price = 0;
int s_distance = 0;
int s_transfer = 0;


//全局变量当前时间
char now_time[10] = { '\0' };


typedef char VertexType[MAX_NAME];


typedef struct Time {
    char set_off_time[10]; //出发时间
    char tag[MAX_INFO]; //火车号或者航班号
    struct Time* next;
}Time;


typedef struct InfoType {
    int distance;          //距离
    int price;             //该段距离的票价    
    Time* time;            //时间结构
}InfoType;

typedef struct ArcNode {
    int adjvex;                //该边所指向的节点位置
    struct ArcNode* nextarc;   //指向下一个结点的指针
    InfoType* info;            //边上的数据
}ArcNode;


typedef struct {
    VertexType city;          //城市名
    ArcNode* firstarc;
}VNode, AdjList[MAXCITYNUM];


typedef struct {
    AdjList plane_vertices;     //飞机邻接表
    AdjList train_vertices;     //火车邻接表
    int vexnum;   //图上的顶点数
}ALGraph;


//队列结构

typedef struct {
    DataType data[MAXCITYNUM];
    int front;
    int rear;
}Queue;

//全局队列
Queue s_queue;

//界面函数
void Run_Process(void);            //运行函数
void Main_InterFace(void);         //主界面函数
void Administrator_Command(void);  //管理员操作提示界面
void Ordinary_Command(char* str);  //用户操作提示界面

//创建交通图
Status CreateGraph(ALGraph* G);

//Floyd算法 求最短路径 flag为交通变量标识
Status Floyd_price(ALGraph* G, int flag);
Status Floyd_price(ALGraph* G, int flag);
Status Floyd_transfer(ALGraph* G, int flag);

//交通图编辑函数
Status Insert_Vex(ALGraph* G, char* v);
Status DeleteVex(ALGraph* G, char* v);
Status DeleteArc(ALGraph* G, char* v, char* w, int flag);
Status InsertArc(ALGraph* G, char* v, char* w, int flag);

//交通图相关其他函数
int Locate_City_Num(ALGraph G, char* s);
int Is_Next_City(ALGraph G, int i, int j, int flag);
void Display_City(ALGraph G);
Status Judge_City_Exist(ALGraph G, char* str);
void Print_All_Arc(ALGraph G,int flag);

//时间处理函数
void Time_Convert(char* t, int n);
void Convert_To_Str(char* str, int n, int m);
void Time_Standard(char* s, int total_second);
int Convert_To_Second(char* s);

//核心代码  flag--交通工具  ctr--控制打印
void Print_Choice_Distance_Path(ALGraph G, int i, int j, int flag);
void Print_Choice_Price_Path(ALGraph G, int i, int j, int flag);
void Print_Choice_Transfer_Path(ALGraph G, int i, int j, int flag);

void Print_Price_Path(ALGraph G, int i, int j, int flag,int ctr);
void Print_Distance_Path(ALGraph G, int i, int j, int flag,int ctr);
void Print_Transfer_Path(ALGraph G, int i, int j, int flag, int ctr);

void Screen_Traffic_Table_Distance(ALGraph G, int from, int to, int flag);
void Screen_Traffic_Table_Price(ALGraph G, int from, int to, int flag);
void Screen_Traffic_Table_Transfer(ALGraph G, int from, int to, int flag);

Status Total_Price(ALGraph G, int i, int j, int flag);
Status Total_Distance(ALGraph G, int i, int j, int flag);
Status Total_Distance_And_Price(ALGraph G, int i, int j, int flag);

Status Detail(ALGraph G, int from, int to, char* set_off_time, int flag);

//队列相关函数
Status InitQueue(Queue* q);
Status EnQueue(Queue* q, DataType data);
DataType DeQueue(Queue* q);                   //出队

//测试函数
void Command(char* str);
//void Adminstrator_InterFace(ALGraph G); //管理员
//void Ordinary_InterFace(ALGraph G);     //用户
void Test3(void);
void Test4(void);
void Test5(void);

int main()
{
    printf("温馨提示:请保证vexnum与文件提供的城市数一致!!!\n");
    system("pause");
    Run_Process();
    /*int p = 600;
    float k = (float)p / train_speed;
    return;*/
    //printf("%d", k);
    //Main_InterFace();
    //Administrator_Command();
    //Test3();
    //Test4();
    //ALGraph G;
    //CreateGraph(&G);
    //Print_All_Arc(G, 0);
    //Test5();
    return 0;
}




void Run_Process(void)
{
    ALGraph Traffic_Graph;
    int choice;   //主页面选择
    int choice1;  //管理员选择
    int choice2;  //用户选择
    int tag = 1;  //操纵主界面
    int tag1;     //操纵管理员界面
    int tag2 = 1; //操纵用户界面
    int flag;     //区分交通工具  0代表高铁 1代表飞机
    char f_city[12] = { '\0' };   //出发城市
    char t_city[12] = { '\0' };   //目的城市
    char new_city[10] = { '\0' }; //新城市

    int city_num1;
    int city_num2;

    Status state;       //状态变量
    
    int creation = 0;     //用来标识当前图是否创建
    int f_creation = 0;   //二重标识


    while (tag == 1)
    {/*主界面设置*/
        Main_InterFace();
        scanf_s("%d", &choice);
        while (choice > 3 || choice < 1)
        {
            printf("Cmd Error!请输入正确的命令!\nCmd:");
            scanf_s("%d", &choice);
        }
        switch (choice) //主界面设置
        {
        case 1:
            printf("正在登录管理员界面,请稍后...\n\n");
            //Adminstrator_InterFace(&Traffic_Graph);
            ///
            ///
            ///
            ///
            ///
            /// 
            /// 
            /// 
            tag1 = 1;
            printf("登录成功!\n");
            while (tag1 == 1)
            {
                Administrator_Command();
                scanf_s("%d", &choice1);
                while (choice1 > 8 || choice1 < 1)
                {
                    printf("Cmd Error!请输入正确的操作命令!\nCmd:");
                    scanf_s("%d", &choice1);
                }
                switch (choice1)
                {
                case 1:
                    if (creation == 1)
                    {
                        printf("当前交通网络已创建!\n");
                        break;
                    }
                    if (creation == 0)
                    {
                        CreateGraph(&Traffic_Graph);
                        creation = 1;
                    }
                    printf("交通网络创建成功!\n");
                    break;
                case 2:
                    if (creation == 0)
                    {
                        printf("请先创建交通网络!\n");
                        break;
                    }
                    Display_City(Traffic_Graph);
                    break;
                case 3:
                    if (creation == 0)
                    {
                        printf("请先创建交通网络!\n");
                        break;
                    }
                    printf("请输入新的城市名:");
                    (void)scanf("%s", new_city);
                    if (Locate_City_Num(Traffic_Graph, new_city) != -1)
                    {
                        printf("当前交通网络已存在%s!\n", new_city);
                        break;
                    }
                    state = Insert_Vex(&Traffic_Graph, new_city);
                    if (state == OK) printf("城市增添成功!\n");
                    break;
                case 4:
                    if (creation == 0)
                    {
                        printf("请先创建交通网络!\n");
                        break;
                    }
                    printf("请输入要删除的城市名:");
                    (void)scanf("%s", new_city);
                    if (Locate_City_Num(Traffic_Graph, new_city) == -1)
                    {
                        printf("当前交通网络不存在%s!\n", new_city);
                        break;
                    }
                    state = DeleteVex(&Traffic_Graph, new_city);
                    if (state == OK) printf("城市删除成功!\n");
                    break;
                case 5:
                    if (creation == 0)
                    {
                        printf("请先创建交通网络!\n");
                        break;
                    }
                    printf("请输入交通工具:0.高铁 1.飞机\nCmd:");
                    scanf_s("%d", &flag);
                    printf("请输入增添路径的起始城市：");
                    (void)scanf("%s", f_city);
                    printf("请输入增添路径的结束城市：");
                    (void)scanf("%s", t_city);
                    if (strcmp(f_city, t_city) == 0)
                    {
                        printf("起止城市相同!\n");
                        break;
                    }
                    state = InsertArc(&Traffic_Graph, f_city, t_city, flag);
                    if (state == OK) printf("路线增添成功!\n");
                    break;
                case 6:
                    if (creation == 0)
                    {
                        printf("请先创建交通网络!\n");
                        break;
                    }
                    printf("请输入交通工具:0.高铁 1.飞机\nCmd:");
                    scanf_s("%d", &flag);
                    printf("请输入删除路径的起始城市：");
                    (void)scanf("%s", f_city);
                    printf("请输入删除路径的结束城市：");
                    (void)scanf("%s", t_city);
                    if (strcmp(f_city, t_city) == 0)
                    {
                        printf("起止城市相同!\n");
                        break;
                    }
                    //Judge_City_Exist(G, f_city);
                    state = DeleteArc(&Traffic_Graph, f_city, t_city, flag);
                    if (state == OK) printf("路线删除成功!\n");
                    else printf("城市删除失败!\n");
                    break;
                case 7:
                    if (creation == 0)
                    {
                        printf("请先创建交通网络!\n");
                        break;
                    }
                    printf("请输入交通工具:0.高铁 1.飞机\nCmd:");
                    scanf_s("%d", &flag);
                    Print_All_Arc(Traffic_Graph, flag);
                    break;
                case 8:
                    tag1 = 0;
                    break;
                default:
                    tag1 = 0;
                    printf("管理员系统崩溃!请重新登录...\n\n\n");
                    break;
                }
            }//while
            ///
            /// 
            ///
            ///
            ///
            ///
            f_creation = 0;
            printf("正在返回主界面,请稍后...\n\n\n");
            break;
        case 2:
            printf("正在登录用户界面,请稍后...\n\n");
            //
            ///
            /// 
            /// 
            /// 
            /// 
            /// 
            printf("登录成功!\n");
            tag2 = 1;
            while (tag2 == 1)
            {
                Ordinary_Command(now_time);
                scanf_s("%d", &choice2);
                while (choice2 > 6 || choice2 < 1)
                {
                    printf("Cmd Error!请输入正确的操作命令!\nCmd:");
                    scanf_s("%d", &choice2);
                }
                switch (choice2)
                {
                case 1:
                    if (creation == 0 && f_creation == 0)//防止管理员修改交通网络之后刷新
                    {
                        CreateGraph(&Traffic_Graph);
                        creation = 1;
                    }

                    /*加载完最短路径和最少费用，后面只做简单查询，不用再修改，避免反复加载，增加复杂度*/
                    Floyd_distance(&Traffic_Graph, 0);
                    Floyd_distance(&Traffic_Graph, 1);
                    Floyd_price(&Traffic_Graph, 0);
                    Floyd_price(&Traffic_Graph, 1);
                    Floyd_transfer(&Traffic_Graph, 0);
                    Floyd_transfer(&Traffic_Graph, 1);
                    f_creation = 1;
                    printf("交通网络加载成功!\n");
                    break;
                case 2:
                    if (f_creation == 0)
                    {
                        printf("请先加载交通网络!\n");
                        break;
                    }
                    printf("请输入交通工具:0.高铁 1.飞机\nCmd:");
                    scanf_s("%d", &flag);
                    printf("请输入出发城市----");
                    (void)scanf("%s", f_city);
                    printf("请输入目的城市----");
                    (void)scanf("%s", t_city);
                    city_num1 = Locate_City_Num(Traffic_Graph, f_city);
                    city_num2 = Locate_City_Num(Traffic_Graph, t_city);
                    if (city_num1 == -1)
                    {
                        printf("当前交通网络中不存在%s城市\n", f_city);
                        break;
                    }
                    if (city_num2 == -1)
                    {
                        printf("当前交通网络中不存在%s城市\n", t_city);
                        break;
                    }

                    if (city_num1 == city_num2)
                    {
                        printf("出发地址与目的地址一样!\n");
                        break;
                    }

                    Screen_Traffic_Table_Distance(Traffic_Graph, city_num1, city_num2, flag);
                    break;
                case 3:
                    if (f_creation == 0)
                    {
                        printf("请先加载交通网络!\n");
                        break;
                    }
                    printf("请输入交通工具:0.高铁 1.飞机\nCmd:");
                    scanf_s("%d", &flag);
                    printf("请输入出发城市----");
                    (void)scanf("%s", f_city);
                    printf("请输入目的城市----");
                    (void)scanf("%s", t_city);
                    city_num1 = Locate_City_Num(Traffic_Graph, f_city);
                    city_num2 = Locate_City_Num(Traffic_Graph, t_city);
                    if (city_num1 == -1)
                    {
                        printf("当前交通网络中不存在%s城市\n", f_city);
                        break;
                    }
                    if (city_num2 == -1)
                    {
                        printf("当前交通网络中不存在%s城市\n", t_city);
                        break;
                    }

                    if (city_num1 == city_num2)
                    {
                        printf("出发地址与目的地址一样!\n");
                        break;
                    }

                    Screen_Traffic_Table_Price(Traffic_Graph, city_num1, city_num2, flag);
                    break;
                case 4:
                    if (f_creation == 0)
                    {
                        printf("请先加载交通网络!\n");
                        break;
                    }
                    printf("请输入交通工具:0.高铁 1.飞机\nCmd:");
                    scanf_s("%d", &flag);
                    printf("请输入出发城市----");
                    (void)scanf("%s", f_city);
                    printf("请输入目的城市----");
                    (void)scanf("%s", t_city);
                    city_num1 = Locate_City_Num(Traffic_Graph, f_city);
                    city_num2 = Locate_City_Num(Traffic_Graph, t_city);
                    if (city_num1 == -1)
                    {
                        printf("当前交通网络中不存在%s城市\n", f_city);
                        break;
                    }
                    if (city_num2 == -1)
                    {
                        printf("当前交通网络中不存在%s城市\n", t_city);
                        break;
                    }

                    if (city_num1 == city_num2)
                    {
                        printf("出发地址与目的地址一样!\n");
                        break;
                    }

                    Screen_Traffic_Table_Transfer(Traffic_Graph, city_num1, city_num2, flag);
                    break;
                case 5:
                    if (f_creation == 0)
                    {
                        printf("请先加载交通网络!\n");
                        break;
                    }
                    printf("请输入交通工具:0.高铁 1.飞机\nCmd:");
                    scanf_s("%d", &flag);
                    Print_All_Arc(Traffic_Graph, flag);
                    break;
                case 6:
                    tag2 = 0;
                    printf("正在返回主界面,请稍后...\n\n\n");
                    break;
                default:
                    printf("用户界面崩溃!请重新登录...\n\n\n");
                    tag2 = 0;
                    break;
                }
            }//while
            ///
            ///
            ///
            /// 
            break;
        case 3:
            printf("正在退出交通咨询系统,请稍后...\n\n\n");
            tag = 0;
            break;
        default:
            printf("系统崩溃!即将退出系统...\n\n");
            tag = 0;
            break;
        }
    }//while
    printf("退出成功!\n");
    return;
}

void Main_InterFace(void)
{
    printf("**********************************Welcome to全国交通咨询系统**********************************\n");
    printf("||                                 请选择你的身份或退出系统                                 ||\n");
    printf("||                            1.管理员        2.用户     3.退出                             ||\n");
    printf("**********************************************************************************************\nCmd:");
}

void Administrator_Command(void)
{
    printf("***********************************************交通网络管理员操作界面***************************************************\n");
    printf("请输入你的操作命令:1.创建交通网络 2.查看当前交通网中已有的城市 3.增添城市 4.删除城市 5.增添指定交通路线 6.删除指定交通路线 7.查看全部列车或者航班 8.返回主界面\n");
    printf("**********************************************************************************************************************\nCmd:");
}

void Ordinary_Command(char* str)
{
    time_t now;
    time(&now);
    struct tm* tm_now;
    tm_now = localtime(&now);
    printf("*********************************************全国交通网络咨询用户界面*********************************************\n");
    printf("当前时间:%d-%d-%d %d:%d\n", tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min);
    printf("请输入咨询业务:1.加载交通网络 2.查询两城市之间距离最短的交通路线 3.查询两城市之间最少费用的交通路线 4.查询两城市之间中转次数最少的交通路线 5.查看全部列车或者航班 6.返回主界面\n");
    Convert_To_Str(str, tm_now->tm_hour, tm_now->tm_min);
    printf("****************************************************************************************************************\n");
    printf("Cmd:");
}

void Display_City(ALGraph G)
{
    printf("当前交通网络中的城市有:\n");
    for (int i = 0; i < G.vexnum; i++)
    {
        printf("%s ", G.train_vertices[i].city);
    }
    printf("\n");
    return;
}

Status CreateGraph(ALGraph* G)
{

    FILE* fp;
    FILE* fp1;
    FILE* fp2;
    ArcNode* p;

    (*G).vexnum = VexNum;

    if ((fp = fopen("city.txt", "r")) == NULL) {
        perror("the file fail to read");
        system("pause");//暂停显示
        exit(1);
    }
    if ((fp1 = fopen("train.txt", "r")) == NULL) {
        perror("the file fail to read");
        system("pause");//暂停显示
        exit(1);
    }
    if ((fp2 = fopen("plane.txt", "r")) == NULL) {
        perror("the file fail to read");
        system("pause");//暂停显示
        exit(1);
    }

    int n = 0;
    while (!feof(fp) && !ferror(fp)) {
        fscanf(fp, "%s", (*G).train_vertices[n].city);
        strcpy((*G).plane_vertices[n].city, (*G).train_vertices[n].city);
        (*G).train_vertices[n].firstarc = NULL;
        (*G).plane_vertices[n].firstarc = NULL;
        n++;
    }

    int t1, t2;
    char str_time[20] = { '\0' };
    int itime;
    int distance;
    int price;
    int num;
    char icon[10] = { '\0' };  //用来缓存车牌号

    Time* ptr, * ptr1;
    while (!feof(fp1) && !ferror(fp1)) {//文件读取结束或出错则退出
        fscanf_s(fp1, "%d%d%d%d%d", &t1, &t2, &distance, &price, &num);
        p = (ArcNode*)malloc(sizeof(ArcNode));
        if (p == NULL) {
            return;
        }
        p->adjvex = t2;
        p->info = (InfoType*)malloc(sizeof(InfoType));
        p->info->distance = distance;
        p->info->price = price;
        p->info->time = (Time*)malloc(sizeof(Time));

        /*单独处理第一个元素*/
        ptr1 = p->info->time;
        fscanf(fp1, "%d%s", &itime,icon);
        Time_Convert(str_time, itime);
        strcpy(ptr1->set_off_time, str_time);
        strcpy(ptr1->tag, icon);
        /*处理除去其他元素*/
        for (int i = 1; i < num; i++)
        {
            fscanf(fp1, "%d%s", &itime,icon);
            Time_Convert(str_time, itime);
            ptr = (Time*)malloc(sizeof(Time));
            strcpy(ptr->set_off_time, str_time);
            strcpy(ptr->tag, icon);
            /*插入到最后，让时间从小到大*/
            ptr1->next = ptr;
            ptr1 = ptr1->next;
        }
        /*将最后的指针置空*/
        ptr1->next = NULL;

        /* 插在表头 */
        p->nextarc = (*G).train_vertices[t1].firstarc;
        (*G).train_vertices[t1].firstarc = p;

    }


    while (!feof(fp2) && !ferror(fp2)) {
        fscanf_s(fp2, "%d%d%d%d%d", &t1, &t2, &distance, &price, &num);
        p = (ArcNode*)malloc(sizeof(ArcNode));
        if (p == NULL) {
            return;
        }
        p->adjvex = t2;
        p->info = (InfoType*)malloc(sizeof(InfoType));
        p->info->distance = distance;
        p->info->price = price;
        p->info->time = (Time*)malloc(sizeof(Time));

        /*单独处理第一个元素*/
        ptr1 = p->info->time;
        fscanf(fp2, "%d%s", &itime, icon);
        Time_Convert(str_time, itime);
        strcpy(ptr1->set_off_time, str_time);
        strcpy(ptr1->tag, icon);
        /*处理除去其他元素*/
        for (int i = 1; i < num; i++)
        {
            fscanf(fp2, "%d%s", &itime, icon);
            Time_Convert(str_time, itime);
            ptr = (Time*)malloc(sizeof(Time));
            strcpy(ptr->set_off_time, str_time);
            strcpy(ptr->tag, icon);
            /*插入到最后，让时间从小到大*/
            ptr1->next = ptr;
            ptr1 = ptr1->next;
        }
        /*将最后的指针置空*/
        ptr1->next = NULL;

        /* 插在表头 */
        p->nextarc = (*G).plane_vertices[t1].firstarc;
        (*G).plane_vertices[t1].firstarc = p;

    }
    return OK;
}

int Locate_City_Num(ALGraph G, char* s)
{
    int n;
    int flag = 0;
    for (n = 0; n < (G.vexnum); n++)
    {
        if (strcmp(s, G.train_vertices[n].city) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag == 1 ? n : -1;
}

Status Judge_City_Exist(ALGraph G, char* str)
{
    if (Locate_City_Num(G, str) == -1)
    {
        printf("当前交通网络中不存在%s城市\n", str);
        return FALSE;
    }
    return TRUE;
}

Status Floyd_distance(ALGraph* G, int flag)
{

    if (flag == 0)
    {/*flag==0代表是火车*/

        int i, j, k;
        for (i = 0; i < (*G).vexnum; i++) {
            for (j = 0; j < (*G).vexnum; j++) {
                if (i == j) {
                    t_distance_dis[i][j] = 0;
                }
                else {
                    t_distance_dis[i][j] = INF;
                }
            }
        }
        memset(t_distance_Path, -1, sizeof(t_distance_Path));

        ArcNode* s;
        for (i = 0; i < (*G).vexnum; i++) {
            s = (*G).train_vertices[i].firstarc;
            while (s != NULL) {
                t_distance_dis[i][s->adjvex] = s->info->distance;
                s = s->nextarc;
            }
        }

        for (k = 0; k < (*G).vexnum; k++) {
            for (i = 0; i < (*G).vexnum; i++) {
                for (j = 0; j < (*G).vexnum; j++) {
                    if (t_distance_dis[i][k] + t_distance_dis[k][j] < t_distance_dis[i][j]) {
                        t_distance_dis[i][j] = t_distance_dis[i][k] + t_distance_dis[k][j];
                        t_distance_Path[i][j] = k;
                    }//if
                }//for j
            }//for i
        }//for k
    }
    else {/*飞机*/
        int i, j, k;
        for (i = 0; i < (*G).vexnum; i++) {
            for (j = 0; j < (*G).vexnum; j++) {
                if (i == j) {
                    p_distance_dis[i][j] = 0;
                }
                else {
                    p_distance_dis[i][j] = INF;
                }
            }
        }
        memset(p_distance_Path, -1, sizeof(p_distance_Path));

        ArcNode* s;
        for (i = 0; i < (*G).vexnum; i++) {
            s = (*G).plane_vertices[i].firstarc;
            while (s != NULL) {
                p_distance_dis[i][s->adjvex] = s->info->distance;
                s = s->nextarc;
            }
        }

        for (k = 0; k < (*G).vexnum; k++) {
            for (i = 0; i < (*G).vexnum; i++) {
                for (j = 0; j < (*G).vexnum; j++) {
                    if (p_distance_dis[i][k] + p_distance_dis[k][j] < p_distance_dis[i][j]) {
                        p_distance_dis[i][j] = p_distance_dis[i][k] + p_distance_dis[k][j];
                        p_distance_Path[i][j] = k;
                    }//if
                }//for j
            }//for i
        }//for k
    }
    return OK;
}

Status Floyd_price(ALGraph* G, int flag)
{
    if (flag == 0) {/*火车*/

        int i, j, k;
        for (i = 0; i < (*G).vexnum; i++) {
            for (j = 0; j < (*G).vexnum; j++) {
                if (i == j) {
                    t_price_dis[i][j] = 0;
                }
                else {
                    t_price_dis[i][j] = INF;
                }
            }
        }
        memset(t_price_Path, -1, sizeof(t_price_Path));


        ArcNode* s;
        for (i = 0; i < (*G).vexnum; i++) {
            s = (*G).train_vertices[i].firstarc;
            while (s) {
                t_price_dis[i][s->adjvex] = s->info->price;
                s = s->nextarc;
            }
        }

        for (k = 0; k < (*G).vexnum; k++) {
            for (i = 0; i < (*G).vexnum; i++) {
                for (j = 0; j < (*G).vexnum; j++) {
                    if (t_price_dis[i][k] + t_price_dis[k][j] < t_price_dis[i][j]) {
                        t_price_dis[i][j] = t_price_dis[i][k] + t_price_dis[k][j];
                        t_price_Path[i][j] = k;
                    }//if
                }//for j
            }//for i
        }//for k
    }
    else {/*飞机*/
        int i, j, k;
        for (i = 0; i < (*G).vexnum; i++) {
            for (j = 0; j < (*G).vexnum; j++) {
                if (i == j) {
                    p_price_dis[i][j] = 0;
                }
                else {
                    p_price_dis[i][j] = INF;
                }
            }
        }
        memset(p_price_Path, -1, sizeof(p_price_Path));


        ArcNode* s;
        for (i = 0; i < (*G).vexnum; i++) {
            s = (*G).plane_vertices[i].firstarc;
            while (s) {
                p_price_dis[i][s->adjvex] = s->info->price;
                s = s->nextarc;
            }
        }

        for (k = 0; k < (*G).vexnum; k++) {
            for (i = 0; i < (*G).vexnum; i++) {
                for (j = 0; j < (*G).vexnum; j++) {
                    if (p_price_dis[i][k] + p_price_dis[k][j] < p_price_dis[i][j]) {
                        p_price_dis[i][j] = p_price_dis[i][k] + p_price_dis[k][j];
                        p_price_Path[i][j] = k;
                    }//if
                }//for j
            }//for i
        }//for k
    }

}

Status Floyd_transfer(ALGraph* G, int flag)
{
    if (flag == 0) {/*火车*/

        int i, j, k;
        for (i = 0; i < (*G).vexnum; i++) {
            for (j = 0; j < (*G).vexnum; j++) {
                if (i == j) {
                    t_transfer_dis[i][j] = 0;
                }
                else {
                    t_transfer_dis[i][j] = INF;
                }
            }
        }
        memset(t_transfer_Path, -1, sizeof(t_transfer_Path));


        ArcNode* s;
        for (i = 0; i < (*G).vexnum; i++) {
            s = (*G).train_vertices[i].firstarc;
            while (s) {
                t_transfer_dis[i][s->adjvex] = 1; //代表中转一次
                s = s->nextarc;
            }
        }

        for (k = 0; k < (*G).vexnum; k++) {
            for (i = 0; i < (*G).vexnum; i++) {
                for (j = 0; j < (*G).vexnum; j++) {
                    if (t_transfer_dis[i][k] + t_transfer_dis[k][j] < t_transfer_dis[i][j]) {
                        t_transfer_dis[i][j] = t_transfer_dis[i][k] + t_transfer_dis[k][j];
                        t_transfer_Path[i][j] = k;
                    }//if
                }//for j
            }//for i
        }//for k
    }
    else {/*飞机*/
        int i, j, k;
        for (i = 0; i < (*G).vexnum; i++) {
            for (j = 0; j < (*G).vexnum; j++) {
                if (i == j) {
                    p_transfer_dis[i][j] = 0;
                }
                else {
                    p_transfer_dis[i][j] = INF;
                }
            }
        }
        memset(p_transfer_Path, -1, sizeof(p_transfer_Path));


        ArcNode* s;
        for (i = 0; i < (*G).vexnum; i++) {
            s = (*G).plane_vertices[i].firstarc;
            while (s) {
                p_transfer_dis[i][s->adjvex] = 1;
                s = s->nextarc;
            }
        }

        for (k = 0; k < (*G).vexnum; k++) {
            for (i = 0; i < (*G).vexnum; i++) {
                for (j = 0; j < (*G).vexnum; j++) {
                    if (p_transfer_dis[i][k] + p_transfer_dis[k][j] < p_transfer_dis[i][j]) {
                        p_transfer_dis[i][j] = p_transfer_dis[i][k] + p_transfer_dis[k][j];
                        p_transfer_Path[i][j] = k;
                    }//if
                }//for j
            }//for i
        }//for k
    }

    return OK;
}

void Print_Choice_Distance_Path(ALGraph G, int i, int j, int flag)
{
    if (flag == 0) {
        if (t_distance_dis[i][j] == INF) {
            printf("无法从%s乘坐高铁到达%s\n", G.train_vertices[i].city, G.train_vertices[j].city);
        }
        else {
            printf("最短路径方案为:%s->", G.train_vertices[i].city);
            Print_Distance_Path(G, i, j, flag, 1);
            printf("%s\n", G.train_vertices[j].city);
            EnQueue(&s_queue, j);
        }
    }
    else {
        if (p_distance_dis[i][j] == INF) {
            printf("无法从%s乘坐飞机到达%s\n", G.plane_vertices[i].city, G.plane_vertices[j].city);
        }
        else {
            printf("最短路径方案为:%s->", G.plane_vertices[i].city);
            Print_Distance_Path(G, i, j, flag, 1);
            printf("%s\n", G.plane_vertices[j].city);
            EnQueue(&s_queue, j);
        }
    }//else

}

void Print_Distance_Path(ALGraph G, int i, int j, int flag,int ctr)
{
    if (flag == 0) {
        int k = t_distance_Path[i][j];
        if (k == -1)
        {
            ArcNode* p = G.train_vertices[i].firstarc;
            while (p->adjvex != j) {
                p = p->nextarc;
            }
            s_price += p->info->price;
            return;
        }
        Print_Distance_Path(G, i, k, flag, ctr);
        if (ctr == 1) {
            printf("%s->", G.train_vertices[k].city);
            EnQueue(&s_queue, k);
        }
        Print_Distance_Path(G, k, j, flag, ctr);
    }//if_train
    else {
        int k = p_distance_Path[i][j];
        if (k == -1)
        {
            ArcNode* p = G.plane_vertices[i].firstarc;
            while (p->adjvex != j) {
                p = p->nextarc;
            }
            s_price += p->info->price;
            return;
        }
        Print_Distance_Path(G, i, k, flag, ctr);
        if (ctr == 1) {
            printf("%s->", G.plane_vertices[k].city);
            EnQueue(&s_queue, k);
        }
        Print_Distance_Path(G, k, j, flag, ctr);
    }//if_plane

}

void Print_Choice_Price_Path(ALGraph G, int i, int j, int flag)
{
    if (flag == 0) {
        if (t_price_dis[i][j] == INF) {
            printf("无法从%s乘坐高铁到达%s\n", G.train_vertices[i].city, G.train_vertices[j].city);
        }
        else {
            printf("最少费用路径方案为:%s->", G.train_vertices[i].city);
            Print_Price_Path(G, i, j, flag,1);
            printf("%s\n", G.train_vertices[j].city);
            EnQueue(&s_queue, j);
        }
    }
    else {
        if (p_price_dis[i][j] == INF) {
            printf("无法从%s乘坐飞机到达%s\n", G.plane_vertices[i].city, G.plane_vertices[j].city);
        }
        else {
            printf("最少费用路径方案为:%s->", G.plane_vertices[i].city);
            Print_Price_Path(G, i, j, flag,1);
            printf("%s\n", G.plane_vertices[j].city);
            EnQueue(&s_queue, j);
        }
    }//else
}

void Print_Price_Path(ALGraph G, int i, int j, int flag,int ctr)
{
    if (flag == 0) {
        int k = t_price_Path[i][j];
        if (k == -1)
        {
            ArcNode* p = G.train_vertices[i].firstarc;
            while (p->adjvex != j) {
                p = p->nextarc;
            }
            s_distance += p->info->distance;
            return;
        }
        Print_Price_Path(G, i, k, flag,ctr);
        if (ctr == 1) {
            printf("%s->", G.train_vertices[k].city);
            EnQueue(&s_queue, k);
        }
        Print_Price_Path(G, k, j, flag,ctr);
    }//if_train
    else {
        int k = p_price_Path[i][j];
        if (k == -1)
        {
            ArcNode* p = G.plane_vertices[i].firstarc;
            while (p->adjvex != j) {
                p = p->nextarc;
            }
            s_distance += p->info->distance;
            return;
        }
        Print_Price_Path(G, i, k, flag, ctr);
        if (ctr == 1) {
            printf("%s->", G.plane_vertices[k].city);
            EnQueue(&s_queue, k);
        }
        Print_Price_Path(G, k, j, flag, ctr);
    }//if_plane
 
}


void Print_Choice_Transfer_Path(ALGraph G, int i, int j, int flag)
{
    if (flag == 0) {
        if (t_transfer_dis[i][j] == INF) {
            printf("无法从%s乘坐高铁到达%s\n", G.train_vertices[i].city, G.train_vertices[j].city);
        }
        else {
            printf("最少中转路径方案为:%s->", G.train_vertices[i].city);
            Print_Transfer_Path(G, i, j, flag, 1);
            printf("%s\n", G.train_vertices[j].city);
            EnQueue(&s_queue, j);
        }
    }
    else {
        if (p_transfer_dis[i][j] == INF) {
            printf("无法从%s乘坐飞机到达%s\n", G.plane_vertices[i].city, G.plane_vertices[j].city);
        }
        else {
            printf("最少中转路径方案为:%s->", G.plane_vertices[i].city);
            Print_Transfer_Path(G, i, j, flag, 1);
            printf("%s\n", G.plane_vertices[j].city);
            EnQueue(&s_queue, j);
        }
    }//else
}

void Print_Transfer_Path(ALGraph G, int i, int j, int flag, int ctr)
{
    if (flag == 0) {
        int k = t_transfer_Path[i][j];
        if (k == -1)
        {
            ArcNode* p = G.train_vertices[i].firstarc;
            while (p->adjvex != j) {
                p = p->nextarc;
            }
            s_distance += p->info->distance;
            s_price += p->info->price;
            return;
        }
        Print_Transfer_Path(G, i, k, flag, ctr);
        if (ctr == 1) {
            printf("%s->", G.train_vertices[k].city);
            EnQueue(&s_queue, k);
        }
        Print_Transfer_Path(G, k, j, flag, ctr);
    }//if_train
    else {
        int k = p_transfer_Path[i][j];
        if (k == -1)
        {
            ArcNode* p = G.plane_vertices[i].firstarc;
            while (p->adjvex != j) {
                p = p->nextarc;
            }
            s_distance += p->info->distance;
            s_price += p->info->price;
            return;
        }
        Print_Transfer_Path(G, i, k, flag, ctr);
        if (ctr == 1) {
            printf("%s->", G.plane_vertices[k].city);
            EnQueue(&s_queue, k);
        }
        Print_Transfer_Path(G, k, j, flag, ctr);
    }//if_plane

}

void Screen_Traffic_Table_Distance(ALGraph G, int from, int to, int flag)
{
    ArcNode* p;
    Time* ptr;
    int time;
    char str_time[10] = { '\0' };
    int tag;
    int distance;
    int set_time;
    
    Status B;


    if (flag == 0) {
        InitQueue(&s_queue);
        p = G.train_vertices[from].firstarc;
        s_price = 0;
        distance = t_distance_dis[from][to];
        ptr = p->info->time;


        B = Total_Price(G, from, to, flag);
        if (B == FALSE) {//无法到达
            return;
        }


        printf("请输入你的出发时间:(格式eg:600代表6:00)\nYour set off time:");
        scanf_s("%d", &set_time);
        Time_Convert(str_time, set_time);


        while (ptr != NULL && strcmp(ptr->set_off_time, str_time) < 0) {
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("-----------------------------------------------------------------------------------\n");
            printf("没有合适的高铁!\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            return;
        }

        printf("-----------------------------------------------------------------------------------\n");
        printf("交通工具:高铁 出发时间:%s 费用:%d 最短路径:%d\n", str_time, s_price, distance);

        Print_Choice_Distance_Path(G, from, to, flag);

        printf("\n具体情况:\n");
        Detail(G, from, DeQueue(&s_queue), ptr->set_off_time, flag);

        printf("-----------------------------------------------------------------------------------\n\n");
    }//if
    else{
        InitQueue(&s_queue);
        p = G.plane_vertices[from].firstarc;
        s_price = 0;
        distance= p_distance_dis[from][to];
        ptr = p->info->time;


        B = Total_Price(G, from, to, flag);
        if (B == FALSE) {//无法到达
            return;
        }


        printf("请输入你的出发时间:(格式eg:600代表6:00)\nYour set off time:");
        scanf_s("%d", &set_time);
        Time_Convert(str_time, set_time);


        while (ptr != NULL && strcmp(ptr->set_off_time, str_time) < 0) {
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("-----------------------------------------------------------------------------------\n");
            printf("没有合适的航班!\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            return;
        }

        printf("-----------------------------------------------------------------------------------\n");
        printf("交通工具:飞机 出发时间:%s 费用:%d 最短路径:%d\n", str_time, s_price,distance);

        Print_Choice_Distance_Path(G, from, to, flag);

        printf("\n具体情况:\n");
        Detail(G, from, DeQueue(&s_queue), ptr->set_off_time, flag);

        printf("-----------------------------------------------------------------------------------\n\n");


    }
}

void Screen_Traffic_Table_Price(ALGraph G, int from, int to, int flag)
{
    ArcNode* p;
    Time* ptr;
    int time;
    char str_time[10] = { '\0' };
    int tag;
    int cost;
    int set_time;//用户选择出发时间
    Status B;   

     
    if (flag == 0) {
        InitQueue(&s_queue);
        p = G.train_vertices[from].firstarc;
        s_distance = 0;
       // float k;
        cost = t_price_dis[from][to];
        ptr = p->info->time;
   

        B = Total_Distance(G, from, to, flag);
        if(B==FALSE){//无法到达
            return;
        }


       /*  k = (float)s_distance / train_speed;
         k = (int)(k * 3600);*/
         printf("请输入你的出发时间:(格式eg:600代表6:00)\nYour set off time:");
         scanf_s("%d", &set_time);
         Time_Convert(str_time, set_time);


         while (ptr != NULL && strcmp(ptr->set_off_time, str_time) < 0) {
             ptr = ptr->next;
         }

         if (ptr == NULL)
         {
             printf("-----------------------------------------------------------------------------------\n");
             printf("没有合适的高铁!\n");
             printf("-----------------------------------------------------------------------------------\n\n");
             return;
         }

        printf("-----------------------------------------------------------------------------------\n");
        printf("交通工具:高铁 出发时间:%s 最少费用:%d 路径:%d\n", str_time,cost,s_distance);

        Print_Choice_Price_Path(G, from, to, flag);

        printf("\n具体情况:\n");
        Detail(G, from,DeQueue(&s_queue),ptr->set_off_time, flag);

        printf("-----------------------------------------------------------------------------------\n\n");


    }//if

    else{
        InitQueue(&s_queue);
        p = G.plane_vertices[from].firstarc;
        s_distance = 0;
       // float k;
        cost = p_price_dis[from][to];
        ptr = p->info->time;


        B = Total_Distance(G, from, to, flag);
        if (B == FALSE) {//无法到达
            return;
        }


       /* k = (float)s_distance / plane_speed;
        k = (int)(k * 3600);*/
        printf("请输入你的出发时间:(格式eg:600代表6:00)\nYour set off time:");
        scanf_s("%d", &set_time);
        Time_Convert(str_time, set_time);


        while (ptr != NULL && strcmp(ptr->set_off_time, str_time) < 0) {
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("-----------------------------------------------------------------------------------\n");
            printf("没有合适的航班!\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            return;
        }

        printf("-----------------------------------------------------------------------------------\n");
        printf("交通工具:飞机 出发时间:%s 最少费用:%d 路径:%d\n", str_time, cost,s_distance);

        Print_Choice_Price_Path(G, from, to, flag);

        printf("\n具体情况:\n");
        Detail(G, from, DeQueue(&s_queue), ptr->set_off_time, flag);

        printf("-----------------------------------------------------------------------------------\n\n");


    }//else
    return;
    
}

void Screen_Traffic_Table_Transfer(ALGraph G, int from, int to, int flag)
{
    ArcNode* p;
    Time* ptr;
    int time;
    char str_time[10] = { '\0' };
    int tag;
    int transfer;
    int set_time;//用户选择出发时间
    Status B;


    if (flag == 0) {
        InitQueue(&s_queue);
        p = G.train_vertices[from].firstarc;
        s_distance = 0;
        s_price = 0;
        // float k;
        transfer = t_transfer_dis[from][to];
        ptr = p->info->time;


        B = Total_Distance_And_Price(G, from, to, flag);
        if (B == FALSE) {//无法到达
            return;
        }


        /*  k = (float)s_distance / train_speed;
          k = (int)(k * 3600);*/
        printf("请输入你的出发时间:(格式eg:600代表6:00)\nYour set off time:");
        scanf_s("%d", &set_time);
        Time_Convert(str_time, set_time);


        while (ptr != NULL && strcmp(ptr->set_off_time, str_time) < 0) {
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("-----------------------------------------------------------------------------------\n");
            printf("没有合适的高铁!\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            return;
        }

        printf("-----------------------------------------------------------------------------------\n");
        printf("交通工具:高铁 出发时间:%s 最少中转次数:%d 费用:%d 路径:%d\n", str_time,transfer, s_price, s_distance);

        Print_Choice_Transfer_Path(G, from, to, flag);

        printf("\n具体情况:\n");
        Detail(G, from, DeQueue(&s_queue), ptr->set_off_time, flag);

        printf("-----------------------------------------------------------------------------------\n\n");


    }//if

    else {
        InitQueue(&s_queue);
        p = G.plane_vertices[from].firstarc;
        s_distance = 0;
        s_price = 0;
        // float k;
        transfer = p_transfer_dis[from][to];
        ptr = p->info->time;


        B = Total_Distance_And_Price(G, from, to, flag);
        if (B == FALSE) {//无法到达
            return;
        }


        /* k = (float)s_distance / plane_speed;
         k = (int)(k * 3600);*/
        printf("请输入你的出发时间:(格式eg:600代表6:00)\nYour set off time:");
        scanf_s("%d", &set_time);
        Time_Convert(str_time, set_time);


        while (ptr != NULL && strcmp(ptr->set_off_time, str_time) < 0) {
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("-----------------------------------------------------------------------------------\n");
            printf("没有合适的航班!\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            return;
        }

        printf("-----------------------------------------------------------------------------------\n");
        printf("交通工具:高铁 出发时间:%s 最少中转次数:%d 费用:%d 路径:%d\n", str_time, transfer, s_price, s_distance);

        Print_Choice_Transfer_Path(G, from, to, flag);

        printf("\n具体情况:\n");
        Detail(G, from, DeQueue(&s_queue), ptr->set_off_time, flag);

        printf("-----------------------------------------------------------------------------------\n\n");


    }//else
    return;

}

Status Detail(ALGraph G, int from,int to,char* set_off_time,int flag)
{
    if (flag == 0) {
        printf("%s->%s", G.train_vertices[from].city, G.train_vertices[to].city);
        for (int i = 0; i < 10 - strlen(G.train_vertices[to].city); i++)
        {
            printf(" ");
        }
        ArcNode* p = G.train_vertices[from].firstarc;
        while (p->adjvex != to) {
            p = p->nextarc;
        }
        float k = (float)p->info->distance / train_speed;
        k = (int)(k * 3600);
        int time = k + Convert_To_Second(set_off_time);
        char str_time[10] = { '\0' };
        Time_Standard(str_time, time);
        printf("高铁号:%s  时间:%s----%s  费用:%d  路程:%d\n", p->info->time->tag, p->info->time->set_off_time, str_time, p->info->price, p->info->distance);

        int temp = DeQueue(&s_queue);
        if (temp == -1) {
            return;
        }
        char new_set_off[10] = { '\0' };
        Time* q = G.train_vertices[to].firstarc->info->time;
        //printf("%p", q->next);
        /*if (q->next == 00000000) {
            printf("好看!");
        }*/
        while (q != NULL&&strcmp(q->set_off_time, str_time) < 0) {
            q = q->next;
        }
        if (q == NULL) {
            printf("你到达%s的时间是%s,当天已经没有从%s开往%s的高铁!\n",G.train_vertices[to].city,str_time,G.train_vertices[to].city,G.train_vertices[temp].city);
            return;
        }
        Detail(G, to,temp,q->set_off_time, flag);

    }//if



    else {
        printf("%s->%s", G.plane_vertices[from].city, G.plane_vertices[to].city);
        for (int i = 0; i < 10 - strlen(G.plane_vertices[to].city); i++)
        {
            printf(" ");
        }
        ArcNode* p = G.plane_vertices[from].firstarc;
        while (p->adjvex != to) {
            p = p->nextarc;
        }
        float k = (float)p->info->distance / plane_speed;
        k = (int)(k * 3600);
        int time = k + Convert_To_Second(set_off_time);
        char str_time[10] = { '\0' };
        Time_Standard(str_time, time);
        printf("航班号:%s  时间:%s----%s  费用:%d  路程:%d\n", p->info->time->tag, p->info->time->set_off_time, str_time,p->info->price,p->info->distance);

        int temp = DeQueue(&s_queue);
        if (temp == -1) {
            return;
        }
        char new_set_off[10] = { '\0' };
        Time* q = G.plane_vertices[to].firstarc->info->time;
        while (q != NULL && strcmp(q->set_off_time, str_time) < 0) {
            q = q->next;
        }
        if (q == NULL) {
            printf("你到达%s的时间是%s,当天已经没有从%s飞往%s的飞机!\n", G.plane_vertices[to].city, str_time, G.plane_vertices[to].city, G.plane_vertices[temp].city);
            return;
        }
        Detail(G, to, temp, q->set_off_time, flag);

    }
    return OK;
 
}


/*使用全局变量计算全程中的费用*/
Status Total_Price(ALGraph G, int i, int j, int flag)
{
    ArcNode* p = G.train_vertices[i].firstarc;
    if (flag == 0) {
        int k = t_distance_Path[i][j];
        if (k == -1)//直达
        {
            if (t_distance_dis[i][j] == INF) {
                printf("无法从%s乘高铁到达%s\n", G.train_vertices[i].city, G.train_vertices[j].city);
                return FALSE;
            }
            else {
                while (p->adjvex != j) {
                    p = p->nextarc;
                }
                s_price += p->info->price;
                return TRUE;
            }
        }
        Print_Distance_Path(G, i, k, flag, 0);
        Print_Distance_Path(G, k, j, flag, 0);
    }//if
    else {
        int k = p_distance_Path[i][j];
        if (k == -1)//直达
        {
            if (p_distance_dis[i][j] == INF) {
                printf("无法从%s乘飞机到达%s\n", G.plane_vertices[i].city, G.plane_vertices[j].city);
                return FALSE;
            }
            else {
                while (p->adjvex != j) {
                    p = p->nextarc;
                }
                s_price += p->info->price;
                return TRUE;
            }
        }
        Print_Distance_Path(G, i, k, flag, 0);
        Print_Distance_Path(G, k, j, flag, 0);
    }//else_plane
    return OK;
}

Status Total_Distance(ALGraph G, int i, int j, int flag)
{
    ArcNode* p= G.train_vertices[i].firstarc;
    if (flag == 0) {
        int k = t_price_Path[i][j];
        if (k == -1)//直达
        {
            if (t_price_dis[i][j] == INF) {
                printf("无法从%s乘高铁到达%s\n", G.train_vertices[i].city, G.train_vertices[j].city);
                return FALSE;
            }
            else {
                while (p->adjvex != j) {
                    p = p->nextarc;
                }
                s_distance += p->info->distance;
                return TRUE;
            }
        }
        Print_Price_Path(G, i, k, flag,0);
        Print_Price_Path(G, k, j, flag,0);
       
    }//if_train
    else {
        int k = p_price_Path[i][j];
        if (k == -1)//直达
        {
            if (p_price_dis[i][j] == INF) {
                printf("无法从%s乘飞机到达%s\n", G.plane_vertices[i].city, G.plane_vertices[j].city);
                return FALSE;
            }
            else {
                while (p->adjvex != j) {
                    p = p->nextarc;
                }
                s_distance += p->info->distance;
                return TRUE;
            }
        }
        Print_Price_Path(G, i, k, flag, 0);
        Print_Price_Path(G, k, j, flag, 0);
    }

    return TRUE;
}

Status Total_Distance_And_Price(ALGraph G, int i, int j, int flag)
{
    ArcNode* p = G.train_vertices[i].firstarc;
    if (flag == 0) {
        int k = t_transfer_Path[i][j];
        if (k == -1)//直达
        {
            if (t_transfer_dis[i][j] == INF) {
                printf("无法从%s乘高铁到达%s\n", G.train_vertices[i].city, G.train_vertices[j].city);
                return FALSE;
            }
            else {
                while (p->adjvex != j) {
                    p = p->nextarc;
                }
                s_distance += p->info->distance;
                s_price += p->info->price;
                return TRUE;
            }
        }
        Print_Transfer_Path(G, i, k, flag, 0);
        Print_Transfer_Path(G, k, j, flag, 0);

    }//if_train
    else {
        int k = p_distance_Path[i][j];
        if (k == -1)//直达
        {
            if (p_distance_dis[i][j] == INF) {
                printf("无法从%s乘飞机到达%s\n", G.plane_vertices[i].city, G.plane_vertices[j].city);
                return FALSE;
            }
            else {
                while (p->adjvex != j) {
                    p = p->nextarc;
                }
                s_distance += p->info->distance;
                s_price += p->info->price;
                return TRUE;
            }
        }
        Print_Transfer_Path(G, i, k, flag, 0);
        Print_Transfer_Path(G, k, j, flag, 0);
    }

    return TRUE;
}

Status Insert_Vex(ALGraph* G, char* v)
{ /* 初始条件: 图G存在,v和图中顶点有相同特征 */
  /* 操作结果: 在图G中增添新顶点v(不增添与顶点相关的弧,留待InsertArc()去做) */
    strcpy((*G).train_vertices[(*G).vexnum].city, v);
    strcpy((*G).plane_vertices[(*G).vexnum].city, v);
    (*G).train_vertices[(*G).vexnum].firstarc = NULL;
    (*G).plane_vertices[(*G).vexnum].firstarc = NULL;
    (*G).vexnum++;
    return OK;
}

Status DeleteVex(ALGraph* G, char* v)
{ /* 初始条件: 图G存在,v是G中某个顶点 */
  /* 操作结果: 删除G中顶点v及其相关的弧 */
    int i, j;
    ArcNode* p, * q, * s,*t;
    j = LocateVex(*G, v); /* j是顶点v的序号 */
    if (j < 0) /* v不是图G的顶点 */
        return ERROR;

    p = (*G).train_vertices[j].firstarc; /* 删除以v为出度的弧或边 */
    s= (*G).plane_vertices[j].firstarc;
    while (p)
    {
        q = p;
        p = p->nextarc;
        free(q);
    }//while
    while (s) {
        t = s;
        s = s->nextarc;
        free(t);
        //(*G).arcnum--; /* 弧或边数减1 */
    }

    (*G).vexnum--; /* 顶点数减1 */

    //改变顶点数组
    for (i = j; i < (*G).vexnum; i++) /* 顶点v后面的顶点前移 */
    {
        (*G).train_vertices[i] = (*G).train_vertices[i + 1];
        (*G).plane_vertices[i] = (*G).plane_vertices[i + 1];
    }

    //改变邻接表
    for (i = 0; i < (*G).vexnum; i++) /* 删除以v为入度的弧或边且必要时修改表结点的顶点位置值 */
    {
        p = (*G).train_vertices[i].firstarc; /* 指向第1条弧或边 */
        s= (*G).plane_vertices[i].firstarc;
        while (p) /* 有弧 */
        {
            if (p->adjvex == j)
            {
                if (p == (*G).train_vertices[i].firstarc) /* 待删结点是第1个结点 */
                {
                    (*G).train_vertices[i].firstarc = p->nextarc;
                    free(p);
                    p = (*G).train_vertices[i].firstarc;/*指针回归表头节点*/
                   // (*G).arcnum--; /* 弧或边数减1 */
                }
            }
            else
            {
                if (p->adjvex > j)
                    p->adjvex--; /* 修改表结点的顶点位置值(序号) */
                q = p;
                p = p->nextarc;
            }//else
        }//while
        while (s) /* 有弧 */
        {
            if (s->adjvex == j)
            {
                if (s == (*G).plane_vertices[i].firstarc) /* 待删结点是第1个结点 */
                {
                    (*G).plane_vertices[i].firstarc = s->nextarc;
                    free(s);
                    s = (*G).plane_vertices[i].firstarc;/*指针回归表头节点*/
                   // (*G).arcnum--; /* 弧或边数减1 */
                }
            }
            else
            {
                if (s->adjvex > j)
                    s->adjvex--; /* 修改表结点的顶点位置值(序号) */
                t = s;
                s = s->nextarc;
            }//else
        }//while

    }//for
   

    
    return OK;
}

Status DeleteArc(ALGraph* G, char* v, char* w,int flag)
{ /* 初始条件: 图G存在,v和w是G中两个顶点 */
  /* 操作结果: 在G中删除弧<v,w>,若G是无向的,则还删除对称弧<w,v> */
    if (flag == 0) {/*火车*/
        ArcNode* p, * q;
        int i, j;
        i = LocateVex(*G, v); /* i是顶点v(弧尾)的序号 */
        j = LocateVex(*G, w); /* j是顶点w(弧头)的序号 */
        if (i < 0 || j < 0 || i == j)
            return ERROR;
        p = (*G).train_vertices[i].firstarc; /* p指向顶点v的第一条出弧 */
        q = p;
        while (p && p->adjvex != j) /* p不空且所指之弧不是待删除弧<v,w> */
        { /* p指向下一条弧 */
            q = p;
            p = p->nextarc;
        }
        if (p && p->adjvex == j) /* 找到弧<v,w> */
        {
            if (p == (*G).train_vertices[i].firstarc) /* p所指是第1条弧 */
                (*G).train_vertices[i].firstarc = p->nextarc; /* 指向下一条弧 */
            else {
                q->nextarc = p->nextarc;
            }
            //free(p);
        }
    }//if

    else {
        ArcNode* p, * q;
        int i, j;
        i = LocateVex(*G, v); /* i是顶点v(弧尾)的序号 */
        j = LocateVex(*G, w); /* j是顶点w(弧头)的序号 */
        if (i < 0 || j < 0 || i == j)
            return ERROR;
        p = (*G).plane_vertices[i].firstarc; /* p指向顶点v的第一条出弧 */
        q = p;
        while (p && p->adjvex != j) /* p不空且所指之弧不是待删除弧<v,w> */
        { /* p指向下一条弧 */
            q = p;
            p = p->nextarc;
        }
        if (p && p->adjvex == j) /* 找到弧<v,w> */
        {
            if (p == (*G).plane_vertices[i].firstarc) /* p所指是第1条弧 */
                (*G).plane_vertices[i].firstarc = p->nextarc; /* 指向下一条弧 */
            //free(p); /* 释放此结点 */
            else {
                q->nextarc = p->nextarc;
            }
        }//if
    }
    return OK;
}

Status InsertArc(ALGraph* G, char* v, char* w,int flag)
{ /* 初始条件: 图G存在,v和w是G中两个顶点 */
  /* 操作结果: 在G中增添弧<v,w>,若G是无向的,则还增添对称弧<w,v> */
    char str_time[10] = { '\0' };
    int i, j;
    int elem;//缓存数据
    int itime;
    i = LocateVex(*G, v);
    j = LocateVex(*G, w);
    if (i < 0 || j < 0)
        return ERROR;

    if (flag == 0) {/*火车*/

        if (Is_Next_City(*G, i, j, flag)==0)//不是相邻城市,新表节点
        {
            ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
            p->info = (InfoType*)malloc(sizeof(InfoType));
            p->info->time = (Time*)malloc(sizeof(Time));
            p->adjvex = j;
            printf("请输入两城市之间的距离:");
            (void)scanf_s("%d", &p->info->distance);
            printf("请输入来两城市之间高铁的费用:");
            (void)scanf_s("%d", &p->info->price);
            printf("请输入要添加高铁的高铁车号:");
            (void)scanf("%s", p->info->time->tag);
            printf("请输入高铁的出发时间:(格式)eg:1020代表10:20)");
            (void)scanf_s("%d", &itime);
            Time_Convert(str_time, itime);
            strcpy(p->info->time->set_off_time, str_time);
            p->info->time->next = NULL;
            p->nextarc = (*G).train_vertices[i].firstarc;
            (*G).train_vertices[i].firstarc = p;
        }//if
        else {//已经是相邻城市，只用添加发车时间就可以
            Time* q = (*G).train_vertices[i].firstarc->info->time;
            Time* s=q;
            Time* p = (Time*)malloc(sizeof(Time));
            printf("请输入要添加高铁的高铁车号:");
            (void)scanf("%s", p->tag);
            printf("请输入高铁的出发时间:(格式)eg:1020代表10:20)");
            (void)scanf_s("%d", &itime);
            Time_Convert(str_time, itime);
            strcpy(p->set_off_time, str_time);
            //p->next = NULL;
            if (strcmp(p->set_off_time, q->set_off_time) < 0)
            {
                (*G).train_vertices[i].firstarc->info->time = p;
                p->next = q;
            }
            else {
                while (q != NULL && strcmp(p->set_off_time, q->set_off_time) > 0) {
                    s = q;
                    q = q->next;
                }
                p->next = s->next;
                s->next = p;
            }
        }//else
    }

    else {/*飞机*/

        if (Is_Next_City(*G, i, j, flag) == 0)//不是相邻城市,新表节点
        {
            ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
            p->info = (InfoType*)malloc(sizeof(InfoType));
            p->info->time = (Time*)malloc(sizeof(Time));
            p->adjvex = j;
            printf("请输入两城市之间的距离:");
            (void)scanf_s("%d", &p->info->distance);
            printf("请输入来两城市之间飞机的费用:");
            (void)scanf_s("%d", &p->info->price);
            printf("请输入要添加航班号:");
            (void)scanf("%s", p->info->time->tag);
            printf("请输入飞机的起飞时间:(格式)eg:1020代表10:20)");
            (void)scanf_s("%d", &itime);
            Time_Convert(str_time, itime);
            strcpy(p->info->time->set_off_time, str_time);
            p->info->time->next = NULL;
            p->nextarc = (*G).plane_vertices[i].firstarc;
            (*G).plane_vertices[i].firstarc = p;
        }//if
        else {//已经是相邻城市，只用添加发车时间就可以
            Time* q = (*G).plane_vertices[i].firstarc->info->time;
            Time* s = q;
            Time* p = (Time*)malloc(sizeof(Time));
            printf("请输入要添加航班号:");
            (void)scanf("%s", p->tag);
            printf("请输入飞机的起飞时间:(格式)eg:1020代表10:20)");
            (void)scanf_s("%d", &itime);
            Time_Convert(str_time, itime);
            strcpy(p->set_off_time, str_time);
            //p->next = NULL;
            if (strcmp(p->set_off_time, q->set_off_time) < 0)
            {
                (*G).train_vertices[i].firstarc->info->time = p;
                p->next = q;
            }
            else {
                while (q != NULL && strcmp(p->set_off_time, q->set_off_time) > 0) {
                    s = q;
                    q = q->next;
                }
                p->next = s->next;
                s->next = p;
            }
        }//else
    }
    return OK;
}

Status InitQueue(Queue* q)
{
    for (int i = 0; i < MAXCITYNUM; i++) {
        (*q).data[i] = -1;
    }
    (*q).front = (*q).rear = 0;
    return OK;
}

Status EnQueue(Queue* q, DataType data) {
    //尾插法
    q->data[q->rear] = data;
    q->rear++;
    return OK;
}

DataType DeQueue(Queue* q)
{
    DataType temp = q->data[q->front];
    q->front++;
    return temp;
}

int Is_Next_City(ALGraph G, int i, int j, int flag)
{
    if (flag == 0)
    {
        ArcNode* p = G.train_vertices[i].firstarc;
        while (p != NULL && p->adjvex != j)
        {
            p = p->nextarc;
        }
        return p == NULL ? 0 : 1;
    }
    else {
        ArcNode* p = G.plane_vertices[i].firstarc;
        while (p != NULL && p->adjvex != j)
        {
            p = p->nextarc;
        }
        return p == NULL ? 0 : 1;
    }
}

void Time_Convert(char* t, int n)
{
    int i = 4;
    while (i >= 0) {
        if (i == 2) t[i] = ':';
        else {
            t[i] = n % 10 + '0';
            n = n / 10;
        }//else
        i--;
    }//while
}

void Convert_To_Str(char* str, int n, int m)
{
    str[0] = n / 10 + '0';
    str[1] = n % 10 + '0';
    str[2] = ':';
    str[3] = m / 10 + '0';
    str[4] = m % 10 + '0';
    return str;
}

int Convert_To_Second(char* s)
{
    return (s[0] - '0') * 10 * 3600 + (s[1] - '0') * 3600 + (s[3] - '0') * 10 * 60 + (s[4] - '0') * 60;
}

void Time_Standard(char* s, int total_second)
{
    int hour = (total_second / 3600) % 24;
    int minute = (total_second % 3600) / 60;
    hour / 10 == 0 ? (s[0] = '0') : (s[0] = hour / 10 + '0');
    s[1] = hour % 10 + '0';
    s[2] = ':';
    minute / 10 == 0 ? (s[3] = '0') : (s[3] = minute / 10 + '0');
    s[4] = minute % 10 + '0';
}

void Print_All_Arc(ALGraph G,int flag)
{
    ArcNode* p;
    Time* t;
    char str_time[12] = { '\0' };
    float k;
    int time;
    if (flag == 0) {
        for (int i = 0; i < (G.vexnum); i++)
        {
            p = G.train_vertices[i].firstarc;
            printf("-----------------------------------------------------------------------------------\n");
            while (p != NULL)
            {
               
                k = (float)p->info->distance / train_speed;
                k = (int)(k * 3600);
                printf("                         %s→%s || 距离:%d || 票价:%d\n", G.train_vertices[i].city, G.train_vertices[p->adjvex].city, p->info->distance, p->info->price);
                t = p->info->time;
                printf("              高铁号******************************************出发时间→到达时间\n");
                while (t != NULL)
                {
                    time= k + Convert_To_Second(t->set_off_time);
                    Time_Standard(str_time, time);
                    printf("              %s                                             %s    %s\n", t->tag, t->set_off_time,str_time);
                    t = t->next;
                }
                p = p->nextarc;
            }//while p
            printf("-----------------------------------------------------------------------------------\n");
        }//for
    }
    else 
    {
        for (int i = 0; i < (G.vexnum); i++)
        {
            p = G.plane_vertices[i].firstarc;
            printf("-----------------------------------------------------------------------------------\n");
            while (p != NULL)
            {

                k = (float)p->info->distance / train_speed;
                k = (int)(k * 3600);
                printf("                         %s→%s || 距离:%d || 票价:%d\n", G.plane_vertices[i].city, G.plane_vertices[p->adjvex].city, p->info->distance, p->info->price);
                t = p->info->time;
                printf("              航班号******************************************起飞时间→到达时间\n");
                while (t != NULL)
                {
                    time = k + Convert_To_Second(t->set_off_time);
                    Time_Standard(str_time, time);
                    printf("              %s                                             %s    %s\n", t->tag, t->set_off_time, str_time);
                    t = t->next;
                }
                p = p->nextarc;
            }//while p
            printf("-----------------------------------------------------------------------------------\n");
        }//for
    }
}


//测试函数
void Test5(void)
{
    ALGraph G;
    CreateGraph(&G);
    Floyd_transfer(&G, 0);
    Screen_Traffic_Table_Transfer(G, 0, 6, 0);
}

void Test4(void)
{
    ALGraph g;
    CreateGraph(&g);
    char new_city[5] = { '\0' };
    //printf("请输入新的城市名:");
    //(void)scanf("%s", new_city);
    //Insert_Vex(&g, new_city);
    //DeleteVex(&g, "杭州");
    //DeleteArc(&g, "汉中", "西安",0);
    InsertArc(&g, "汉中", "北京", 0);
    Floyd_price(&g, 0);
    Screen_Traffic_Table_Price(g, Locate_City_Num(g, "汉中"), Locate_City_Num(g, "北京"), 0);
    DeleteArc(&g, "汉中", "西安", 0);
    Floyd_price(&g, 0);
    Screen_Traffic_Table_Price(g, Locate_City_Num(g, "汉中"), Locate_City_Num(g, "西安"), 0);


    return;
}

void Test3(void)
{
    int i, j, k, n;
    VertexType v1, v2;
    ALGraph g;
    char f_city[12] = { '\0' };
    char t_city[12] = { '\0' };
    printf("请输入出发城市----");
    (void)scanf("%s", f_city);
    printf("请输入出发城市----");
    (void)scanf("%s", t_city);
    CreateGraph(&g);
    int city_num1 = Locate_City_Num(g, f_city);
    int city_num2 = Locate_City_Num(g, t_city);
    if (city_num1 == -1)
    {
        printf("当前交通网络中不存在%s城市\n", f_city);
        return;
    }
    if (city_num2 == -1)
    {
        printf("当前交通网络中不存在%s城市\n", t_city);
        return;
    }
    Floyd_distance(&g, 0);
    //Floyd_price(&g, 0);
    Screen_Traffic_Table_Distance(g, city_num1, city_num2, 0);
}

void Command(char* str)
{
    time_t now;
    time(&now);
    struct tm* tm_now;
    tm_now = localtime(&now);
    //printf("now time:%d-%d-%d %d:%d", tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min);
    printf("*********************全国交通网络咨询****************\n");
    printf("当前时间:%d-%d-%d %d:%d\n", tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min);
    printf("请输入咨询业务:1.创建交通网络 2.最短距离 3.最少费用 4.退出\n");
    Convert_To_Str(str, tm_now->tm_hour, tm_now->tm_min);
    printf("Cmd:");
}

int LocateVex(ALGraph G, char* u)
{ /* 初始条件: 图G存在,u和G中顶点有相同特征 */
  /* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (strcmp(u, G.train_vertices[i].city) == 0)
            return i;
    return -1;
}

//
//void Adminstrator_InterFace(ALGraph* G)
//{
//    int choice1; //管理员选择
//    int tag1 = 1; //操纵管理员界面
//    int flag;   //区分交通工具  0代表高铁 1代表飞机
//    char f_city[12] = { '\0' };  //出发城市
//    char t_city[12] = { '\0' };  //目的城市
//    char new_city[12] = { '\0' };
//    Status state;
//    int city_num;
//
//    printf("登录成功!\n");
//    while (tag1 == 1)
//    {
//        Administrator_Command();
//        scanf_s("%d", &choice1);
//        while (choice1 > 7 || choice1 < 1)
//        {
//            printf("Cmd Error!请输入正确的操作命令!\nCmd:");
//            scanf_s("%d", &choice1);
//        }
//        switch (choice1)
//        {
//        case 1:
//            if (creation == 0)
//            {
//                CreateGraph(&G);
//                creation = 1;
//            }
//            printf("交通网络创建成功!\n");
//            break;
//        case 2:
//            if (creation == 0)
//            {
//                printf("请先创建交通网络!\n");
//                break;
//            }
//            Display_City(&G);
//            break;
//        case 3:
//            if (creation == 0)
//            {
//                printf("请先创建交通网络!\n");
//                break;
//            }
//            printf("请输入新的城市名:");
//            (void)scanf("%s", new_city);
//            if (Locate_City_Num2(&G, new_city) != -1)
//            {
//                printf("当前交通网络已存在%s!\n", new_city);
//                break;
//            }
//            state = Insert_Vex(&G, new_city);
//            if (state == OK) printf("城市增添成功!\n");
//            break;
//        case 4:
//            if (creation == 0)
//            {
//                printf("请先创建交通网络!\n");
//                break;
//            }
//            printf("请输入要删除的城市名:");
//            (void)scanf("%s", new_city);
//            state = DeleteVex(&G, new_city);
//            if (state == OK) printf("城市删除成功!\n");
//            break;
//        case 5:
//            if (creation == 0)
//            {
//                printf("请先创建交通网络!\n");
//                break;
//            }
//            printf("请输入交通工具:0.高铁 1.飞机\n");
//            scanf_s("%d", &flag);
//            printf("请输入增添路径的起始城市：\n");
//            scanf("%s", f_city);
//            printf("请输入增添路径的结束城市：\n");
//            scanf("%s", t_city);
//            state = InsertArc(&G, f_city, t_city, flag);
//            if (state == OK) printf("路线增添成功!\n");
//            break;
//        case 6:
//            if (creation == 0)
//            {
//                printf("请先创建交通网络!\n");
//                break;
//            }
//            printf("请输入交通工具:0.高铁 1.飞机\n");
//            scanf_s("%d", &flag);
//            printf("请输入删除路径的起始城市：\n");
//            scanf("%s", f_city);
//            printf("请输入删除路径的结束城市：\n");
//            scanf("%s", t_city);
//            //Judge_City_Exist(G, f_city);
//            state = DeleteArc(&G, f_city, t_city, flag);
//            if (state == OK) printf("路线删除成功!\n");
//            break;
//        case 7:
//            tag1 = 0;
//            break;
//        default:
//            tag1 = 0;
//            printf("管理员系统崩溃!请重新登录...\n\n\n");
//            break;
//        }
//    }//while
//
//}
//
//int Locate_City_Num2(ALGraph* G, char* s)
//{
//    int n;
//    int flag = 0;
//    for (n = 0; n < ((*G).vexnum); n++)
//    {
//        if (strcmp(s, (*G).train_vertices[n].city) == 0)
//        {
//            flag = 1;
//            break;
//        }
//    }
//
//    return flag == 1 ? n : -1;
//}
//
//ALGraph Ordinary_InterFace(ALGraph G)
//{
//    int choice2; //用户选择
//    int tag2 = 1; //用户界面控制
//    int flag;   //区分交通工具  0代表高铁 1代表飞机
//    char f_city[12] = { '\0' };  //出发城市
//    char t_city[12] = { '\0' };  //目的城市
//    char new_city[12] = { '\0' };
//    int city_num1;
//    int city_num2;
//    Status state;
//    while (tag2 == 1)
//    {
//        Ordinary_Command(now_time);
//        scanf_s("%d", &choice2);
//        while (choice2 > 4 || choice2 < 1)
//        {
//            printf("Cmd Error!请输入正确的操作命令!\nCmd:");
//            scanf_s("%d", &choice2);
//        }
//        switch (choice2)
//        {
//        case 1:
//            if (creation == 0)//防止管理员修改交通网络之后刷新
//            {
//                CreateGraph(&G);
//                creation = 1;
//            }
//            /*加载完最短路径和最少费用，后面只做简单查询，不用再修改，避免反复加载，增加复杂度*/
//            Floyd_distance(&G, 0);
//            Floyd_price(&G, 0);
//            printf("交通网络加载成功!\n");
//            break;
//        case 2:
//            if (creation == 0)
//            {
//                printf("请先加载交通网络!\n");
//                break;
//            }
//            printf("请输入交通工具:0.高铁 1.飞机\n");
//            scanf_s("%d", &flag);
//            printf("请输入出发城市----");
//            (void)scanf("%s", f_city);
//            printf("请输入出发城市----");
//            (void)scanf("%s", t_city);
//            city_num1 = Locate_City_Num(G, f_city);
//            city_num2 = Locate_City_Num(G, t_city);
//            if (city_num1 == -1)
//            {
//                printf("当前交通网络中不存在%s城市\n", f_city);
//                break;
//            }
//            if (city_num2 == -1)
//            {
//                printf("当前交通网络中不存在%s城市\n", t_city);
//                break;
//            }
//            //Floyd_distance(G, 0);
//            //Floyd_price(&g, 0);
//            Screen_Traffic_Table_Distance(G, city_num1, city_num2, 0);
//            break;
//        case 3:
//            if (creation == 0)
//            {
//                printf("请先加载交通网络!\n");
//                break;
//            }
//            printf("请输入交通工具:0.高铁 1.飞机\n");
//            scanf_s("%d", &flag);
//            printf("请输入出发城市----");
//            (void)scanf("%s", f_city);
//            printf("请输入出发城市----");
//            (void)scanf("%s", t_city);
//            city_num1 = Locate_City_Num(G, f_city);
//            city_num2 = Locate_City_Num(G, t_city);
//            if (city_num1 == -1)
//            {
//                printf("当前交通网络中不存在%s城市\n", f_city);
//                break;
//            }
//            if (city_num2 == -1)
//            {
//                printf("当前交通网络中不存在%s城市\n", t_city);
//                break;
//            }
//            //Floyd_distance(G, 0);
//            //Floyd_price(&g, 0);
//            Screen_Traffic_Table_Price(G, city_num1, city_num2, 0);
//            break;
//        case 4:
//            tag2 = 0;
//            printf("正在返回主界面,请稍后...\n\n\n");
//            break;
//        default:
//            printf("用户界面崩溃!请重新登录...\n\n\n");
//            tag2 = 0;
//            break;
//        }
//    }//while
//    return G;
//}


//void Screen_Traffic_Table_Price(ALGraph G, int from, int to, int flag)
//{
//    ArcNode* p;
//    Time* ptr;
//    int time;
//    char str_time[10] = { '\0' };
//    int tag;
//    int cost;
//    Status B;
//
//
//    if (flag == 0) {
//        InitQueue(&s_queue);
//        p = G.train_vertices[from].firstarc;
//        s_distance = 0;
//        tag = 0;
//        float k;
//        cost = t_price_dis[from][to];
//        ptr = p->info->time;
//        while (ptr) {
//
//            B = Total_Distance(G, from, to, flag);
//
//            if (B == FALSE) {//无法到达
//                break;
//            }
//
//            if (tag == 0) {
//                k = (float)s_distance / train_speed;
//                k = (int)(k * 3600);
//                tag = 1;
//            }
//            time = k + Convert_To_Second(ptr->set_off_time);
//            Time_Standard(str_time, time);
//            printf("-----------------------------------------------------------------------------------\n");
//            printf("交通工具:高铁");
//                Print_Choice_Price_Path(G, from, to, flag);
//            printf("具体情况:\n");
//            Detail(G, from, DeQueue(&s_queue), ptr->set_off_time, flag);
//            printf("\n交通工具:高铁 出发时间:%s 达到时间:%s 费用:%d\n", ptr->set_off_time, str_time, cost);
//
//            printf("-----------------------------------------------------------------------------------\n\n");
//            ptr = ptr->next;
//        }
//    }//if
//
//    else {
//        InitQueue(&s_queue);
//        p = G.plane_vertices[from].firstarc;
//        s_distance = 0;
//        tag = 0;
//        float k;
//        cost = p_price_dis[from][to];
//        ptr = p->info->time;
//        while (ptr) {
//
//            B = Total_Distance(G, from, to, flag);
//
//            if (B == FALSE) {//无法到达
//                break;
//            }
//
//            if (tag == 0) {
//                k = (float)s_distance / plane_speed;
//                k = (int)(k * 3600);
//                tag = 1;
//            }
//            time = k + Convert_To_Second(ptr->set_off_time);
//            Time_Standard(str_time, time);
//            printf("-----------------------------------------------------------------------------------\n");
//            Print_Choice_Price_Path(G, from, to, flag);
//            printf("具体情况:\n");
//            Detail(G, from, DeQueue(&s_queue), ptr->set_off_time, flag);
//            printf("\n交通工具:飞机 出发时间:%s 达到时间:%s 费用:%d\n", ptr->set_off_time, str_time, cost);
//
//            printf("-----------------------------------------------------------------------------------\n\n");
//            ptr = ptr->next;
//        }
//    }//plane
//
//
//}




//void DFS(ALGraph G,int u)
//{
//    //d[i]表示从u到i节点的最短路径
//    for (int i = 0; i < G.vexnum; ++i)
//    {
//        d[i] = INF; //初始化长度
//    }
//    visited[u] = TRUE;
//    d[u] = 0;
//    EnQueue(Q, u);
//    while (!IsEmpty(Q)) {
//        DeQueue(Q, u);
//        for (w = FirstNeighour(G, u); w >= 0; w = NextNeighbor(G, u, w))
//        {
//            if (!visited[w])
//            {
//                visited[w] = TRUE;
//                d[w] = d[u] + 1;    //中转站加1
//                EnQueue(Q, w);   
//            }
//        }//if
//    }//while
//}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

```
city txt
汉中 西安 北京 上海 南昌
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

```
train txt
0 1 400 96 8 650 D0101 655 D0311 950 D0102 1250 D0103 1255 D0312 1550 D0104 1850 D0105 1855 D0313 
0 3 1600 773 5 650 D0301 950 D0302 1250 D0303 1550 D0404 1855 D0505
0 4 1200 574 5 650 D0401 950 D0402 1250 D0403 1550 D0404 1855 D0405
1 0 400 96 5 650 D1001 950 D1002 1250 D1003 1550 D1004 1855 D1005
1 2 800 515 8 650 D1201 810 D0311 950 D1202 1250 D1203 1410 D0312 1550 D1204 1855 D1205 2010 D0313
1 3 800 712 5 650 D1301 950 D1302 1250 D1303 1550 D1304 1855 D1305
1 4  800 576 5 650 D1401 950 D1402 1250 D1403 1550 D1404 1855 D1405
2 1 800 515 5 650 D2101 950 D2102 1250 D2103 1550 D2104 1855 D2105
2 3 600 631 5 650 D2301 950 D2302 1250 D2303 1550 D2304 1855 D2305
3 0 1600 773 5 650 D3001 950 D3002 1250 D3003 1550 D3004 1855 D5005
3 1 800 712 5 650 D3101 950 D3102 1250 D3103 1550 D3104 1855 D3105
3 2 600 631 5 650 D3201 950 D3202 1250 D3203 1550 D3204 1855 D3205
3 4 400 336 5 650 D3401 950 D3402 1250 D3403 1550 D3404 1855 D3405
4 0 1200 574 5 650 D4001 950 D4002 1250 D4003 1550 D4004 1855 D4005
4 1 800 576 5 650 D4101 950 D4102 1250 D4103 1550 D4104 1855 D4105
4 3 400 336 5 650 D4301 950 D4302 1250 D4303 1550 D4304 1855 D4305
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

```
plane txt
0 3 1200 1500 4 600 F0301 800 F0302 1000 F0303 1200 F0304
3 0 1200 1500 4 600 F3001 800 F3002 1000 F3003 1200 F3004
0 1 900 1000 4 700 F0101 800 F0102 900 F0103 1000 F0104
1 0 900 1000 4 700 F1001 800 F1002 900 F1003 1000 F1004
0 2 800 900 4 850 F0201 950 F0202 1050 F0203 1120 F0204
2 0 800 900 4 850 F2001 950 F2002 1050 F2003 1220 F2004
1 3 500 450 4 750 F1301 850 F1302 950 F1303 1050 F1304
3 1 500 450 4 750 F3101 850 F3102 950 F3103 1050 F3104
1 2 600 520 4 650 F120 1850 F1202 1050 F1203 1250 F1204
2 1 600 520 4 650 F2101 850 F2102 1050 F2103 1250 F2104
1 4 1000 1200 3 820 F1401 940 F1402 1030 F1403
4 1 1000 1200 3 820 F4101 940 F4102 1030 F4103
2 3 1100 1250 4 640 F2301 840 F2302 1040 F2303 1240 F2304
3 2 1100 1250 4 640 F3201 840 F3202 1040 F3203 1240 F3204
2 4 1300 1650 3 740 F2401 850 F2402 930 F2403
4 2 1300 1650 3 740 F4201 850 F4202 930 F4203
3 4 1500 1800 3 820 F3401  930 F3402 1040 F3403
4 3 1500 1800 3 820 F4301 930 F4302 1040 F4303
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

