#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<Windows.h>

//��������
const int N = 300;

//��������
#define Elemtype int

//����
#define Ptrtype BSTptr
#define MAXNODE 100

//��̬����
#define MAXLENGTH 100
#define null -858993460

//״̬����
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

//BST��AVL���ýṹ
typedef struct Node {
    Elemtype elem;
    struct Node* Lch;
    struct Node* Rch;
    int height;
}BST, * BSTptr;

//LBST��̬����
typedef struct {
    Elemtype data;
    int Lch, Rch;
}LBST[MAXLENGTH];


//���нṹ
typedef struct QNode {
    Ptrtype ptr;
    struct Node* next;
}QNode, * Queueptr;       //���ö���ָ�룬�����޸�

typedef struct {
    Queueptr front;
    Queueptr rear;
}Queue;

//��ջ
//typedef struct Node{
//    int data;
//    struct Node* pNext;
//}NODE,*PNODE;
//
//typedef struct STACK{
//    PNODE pTop;
//    PNODE pBottom;
//}STACK,*PSTACK;

//BST���Ĵ���
Status Search(BSTptr T, Elemtype elem, BSTptr Parent, BSTptr* p);//����
BSTptr Init_Node(Elemtype elem);         //��ʼ��һ���ڵ�
Status Insert(BSTptr* T, Elemtype elem);

//������ز���
Status Inorder_Recursion(BSTptr T);      //��������ݹ��㷨���ݹ鲻��ջ��ԭ���ǵݹ麯�����������ջ������
//Status Inorder_NonRecursion(BSTptr T); //��������ǵݹ��㷨
Status Levelorder(BSTptr T);             //��α���
Status Visit(BSTptr T);                  //���ʽڵ�ֵ
Elemtype MAXElem(BSTptr T);              //�õ����ֵ
Elemtype MINElem(BSTptr T);              //�õ����ֵ

//AVL����ز���
int Judge_layer(BSTptr T, Elemtype elem);             //�ж�elem�ڵ�Ĳ�����������
BSTptr Bulid_AVL(BSTptr T, Elemtype elem);            //�ж�һ��BST���Ƿ�ΪAVL��
BSTptr LL_Rotate(BSTptr T);
BSTptr RL_Rotate(BSTptr T);
BSTptr LR_Rotate(BSTptr T);
BSTptr RR_Rotate(BSTptr T);
int GetHeight(BSTptr T);
int Max(int a, int b);

//ɾ������
BSTptr Delete(BSTptr T,BSTptr p,BSTptr parent);
BSTptr Get_Delete_Node_And_Parent(BSTptr T, Elemtype elem,BSTptr* parent);  //���丸�ڵ���ָ����ʽ����

//��ӡ���ṹ
void Screen_Reveal(BSTptr T);

//LBST��ز���
int creat_LBST(LBST t, Elemtype* L, int len);
int insert_LBST(LBST t, Elemtype elem,int len);
Status visit_LBST(int R, LBST t);
float Search_Success_Average_LBST(LBST T, Elemtype* L, int count);
int Search_LBST(LBST T, Elemtype data);
Status Delete_LBST(LBST T, int p, int parent);
int Get_LBST_Node_And_Parent(LBST T, Elemtype data, int* parent);

////ջ�Ĳ���
//void Stack_Init(PSTACK);//��ʼ��ջ
//void Stack_Push(PSTACK, BSTptr* T);
//int Stack_Empty(PSTACK);
//void Stack_Pop(PSTACK, BSTptr* T);


//���в���
Status InitQueue(Queue* q);
Status EnQueue(Queue* q, Ptrtype ptr);
Ptrtype DeQueue(Queue* q);                   //����
//Status PrintQueue(Queue q);                //���ڵ�ǰ���д�ž�Ϊָ�룬����Ҫ��ӡ

//�ļ�����
int Open_File(Elemtype L[]);     //���򿪵��ļ����������L��->LҲ���Թ�����һ������
Elemtype Convert(char* str);    //���ı��е��ַ��������Elemtype�ͣ�int)

//���Ժ���
Status Test(void);
Status Test2(void);
Status Test3(void);

//���к���
Status Run_process(void);
Status Command(void);






int main()
{
    Run_process();
    //Test();
    //Test2();
    //Test3();
    //Test4();
    return 0;
}



Status Run_process(void)
{
    system("mode con cols=300"); //����̨ÿ��������300

    //��������
    BSTptr tree = NULL;   //��������
    LBST Ltree;           //��̬����
    BSTptr p;             //BST��ʱ����
    BSTptr parent;        //BSTdelete����ʹ��
    int P;                //LBST��ʱ����
    int Parent;           //LBSTdelete����ʹ��
    int choice;           //ѡ������
    int elem;             //elem��ʱ����
    int flag = 1;         //�����Ƿ��˳�
    int tag = 0;          //�������������
    //int L[20];//�����������ɲ���20��
    Elemtype L[MAXNODE];  //���ݻ�����
    int count = 0;        //����������ʾ�ļ��е���������
    int layer;            //�жϲ��
    int sum = 0;          //��ƽ�����ʱ��
    //char ch[50];        //����������Ʒ�


    while (flag) {
        Command();
        (void)scanf("%d", &choice);
        while (choice < 1 || choice>11) {
            printf("please input proper Cmd!\nCmd:");
            (void)scanf("%d", &choice);
        }
        switch (choice) {
        case 1:
            if (tag == 1) {
                printf("��ǰBST���Ѵ���!");
                break;
            }
            tree = NULL;
            count = Open_File(L);
            for (int j = 0; j < count; j++) {
                Insert(&tree, L[j]);
            }
            printf("BST�������ɹ�!");
            tag = 1;
            break;
        case 2:
            if (tag == 2) {
                printf("��ǰLBST���Ѵ���!");
                break;
            }
            count = Open_File(L);
            count=creat_LBST(Ltree, L, count);  //L�п��ܴ�����ͬԪ�أ���Ҫ����ͳ��count
            printf("LBST�������ɹ�!");
            tag = 2;
            break;
        case 3:
            if (tag == 3) {
                printf("��ǰAVL���Ѵ���!");
                break;
            }
            tree = NULL;
            count = Open_File(L);
            for (int j = 0; j < count; j++) {
                tree = Bulid_AVL(tree, L[j]);
            }
            printf("AVL�������ɹ�!");
            tag = 3;
            break;
        case 4:
            if (tag == 0) {
                printf("���ȹ���BST��LBST����AVL��!\n");
                break;
            }
            else {
                printf("������Ҫ���ҵ�ֵ:");
                scanf_s("%d", &elem);
                if (tag != 2) {
                    if (Search(tree, elem, NULL, &p) == TRUE) {
                        printf("��ǰ���д��ڸýڵ㣬������λ��%d��!", Judge_layer(tree, p->elem));
                    }
                    else {
                        printf("��ǰ����û�иýڵ�!");
                    }
                }//tag!=2
                else {//tag==2->LBST
                    layer = Search_LBST(Ltree, elem);
                    layer == -1 ? printf("��ǰ����û�иýڵ�!") : printf("��ǰ���д��ڸýڵ㣬������λ��%d��!", layer);
                }

            }
            break;
        case 5:
            if (tag == 0) {
                printf("���ȹ���BST,LBST����AVL��!\n");
                break;
            }
            if (tag != 2) {
                for (int i = 0; i < count; i++) {
                    layer = Judge_layer(tree, L[i]);
                    //if (layer == -1) {
                    //    //���޸ýڵ㣬�������
                    //    printf("��%d�ڵ�\n", L[i]);
                    //    continue;
                    //}
                    sum += layer;
                }
                count==0?printf("��ǰ����û��Ԫ��!"):printf("ƽ�����ҳ���Ϊ%.2f", (float)sum / (float)count);
            }//tag!=2
            else {
                count==0?printf("��ǰ����û��Ԫ��!"):printf("ƽ�����ҳ���Ϊ%.2f", Search_Success_Average_LBST(Ltree, L, count));
            }
            sum = 0;
            break;
        case 6:
            if (tag == 0) {
                printf("���ȹ���BST,LBST����AVL��!\n");
                break;
            }
            printf("��������Ҫ����Ľڵ�ֵ:");
            scanf_s("%d", &elem);
            if (tag == 2) {//LBST
                if (count == N) {
                    printf("��ǰLBST�������޷�����!");
                    break;
                }
                count++;
                (insert_LBST(Ltree, elem, count) == 1) ? printf("��ǰLBST���Ѵ���elem--%d�ڵ�!", elem) : printf("����ɹ�!");
            }

            else {
                if (Judge_layer(tree, elem) != -1) {
                    //˵����ǰ���д���elem
                    printf("elem--%d�Ѿ�����!", elem);
                }
                else {
                    count++;
                    L[count - 1] = elem;
                    if (tag == 1) {
                        Insert(&tree, L[count - 1]);
                    }//BST
                    else {
                        tree = Bulid_AVL(tree, L[count - 1]);
                    }//AVL
                    printf("����ɹ�!");
                }
            }
            break;
        case 7:
            if (tag == 3) {
                printf("AVL��ɾ����������ӣ��������¹���AVL��!");
                break;
            }
            if (tag == 0) {
                printf("���ȹ���BST����LBST��!\n");
                break;
            }
            printf("������Ҫɾ���Ľڵ�ֵ:");
            scanf_s("%d", &elem);
            //BST����������ʽ
            if (tag == 1) {
                p = Get_Delete_Node_And_Parent(tree, elem, &parent);
                if (p == NULL) {
                    printf("��ǰBST����elem--%d�ڵ�", elem);
                }
                else {
                    tree = Delete(tree, p, parent);
                    printf("ɾ���ɹ�!\n��������������:\n");
                    Inorder_Recursion(tree);
                }
            }

            //LBST��̬�����ʾ
            if (tag == 2) {
                P = Get_LBST_Node_And_Parent(Ltree, elem, &Parent);
                if (P == null) {
                    printf("��ǰBST����elem--%d�ڵ�", elem);
                }
                else {
                    Delete_LBST(Ltree, P, Parent);
                    printf("ɾ���ɹ�!\n��������������:\n");
                    Ltree[0].data==null?printf(" "):visit_LBST(0, Ltree);
                }
            }
            break;
        case 8:
            if (tag == 0) {
                printf("���ȹ���BST��LBST����AVL��!\n");
                break;
            }
            printf("��������������:\n");
            if (tag == 1||tag==3) {
                Inorder_Recursion(tree);
            }
            else {
                if (Ltree[0].data == null) {
                    printf(" ");
                }
                else {
                    visit_LBST(0, Ltree);
                }
            }
            //tag == 2 ? (Ltree[0].data==null?printf(" "):visit_LBST(0, Ltree)) : Inorder_Recursion(tree);
            break;
        case 9:
            if (tag == 0) {
                printf("���ȹ���BST����AVL��!\n");
                break;
            }
            if (tag == 2) {
                printf("��δ����LBST���Ĳ�α���!");
                break;
            }
            printf("��α����������:\n");
            Levelorder(tree);
            break;
        case 10:
            if (tag == 0) {
                printf("���ȴ���AVL��!");
                break;
            }
            if (tag == 1 || tag == 2) {
                printf("BST����LBST������δ������ӡ����,��ӡ���ܽ�����AVL��!");
                break;
            }
            printf("����������������:\n");
            if (count == 0) {
                //AVL����û��Ԫ�أ�ֱ�Ӵ�ӡ��
                printf("  @");
            }
            else if (count == 1) {
                //AVL���н���һ��Ԫ�أ���ӡΨһ
                printf("   %d\n  / \\\n @   @", tree->elem);
            }
            else {
                //AVL�������ٺ�������Ԫ��
                Screen_Reveal(tree);
            }
            break;
        case 11:
            flag = 0;
            printf("�˳��ɹ�!");
            break;
        default:
            break;
        }//switch
        printf("\n\n"); //��ʽ����
    }//while flag

    return OK;
}


Status Test(void)
{
    Elemtype L[100];
    for (int i = 1; i <= 100; i++) {
        L[i - 1] = i;
    }
    BSTptr tree = NULL;
    int layer;
    int sum = 0;
    system("mode con cols=100");//ÿ�����100
    for (int i = 0; i < 100; i++) {
        tree = Bulid_AVL(tree, L[i]);
    }
    //printf("��������������:\n");
    //Inorder_Recursion(tree);
    //printf("\n");
    Screen_Reveal(tree);
    //Levelorder(tree);
    //printf("\n%d", GetHeight(tree));
    //Elemtype g[3] = { 1,2,3 };
    //for (int i = 0; i < 3; i++) {
    //    layer = Judge_layer(tree, g[i]);
    //    if (layer == -1) {
    //        //���޸ýڵ㣬�������
    //        printf("��%d�ڵ�\n", g[i]);
    //        continue;
    //    }
    //    printf("%d�ڵ��ڵ�%d��\n", g[i], layer);
    //    sum += layer;
    //}

    //printf("LR��ת��\n");
    //tree=LR_Rotate(tree);
    //for (int i = 0; i < 7; i++) {
    //    layer = Judge_layer(tree, g[i]);
    //    if (layer == -1) {
    //        //���޸ýڵ㣬�������
    //        printf("��%d�ڵ�\n", g[i]);
    //        continue;
    //    }
    //    printf("%d�ڵ��ڵ�%d��\n", g[i], layer);
    //    sum += layer;
    //}
    //printf("%d,%d", GetHeight(tree->Lch), GetHeight(tree->Rch));
   // printf("������%d�Σ�ƽ�����ҳ���Ϊ%d\n", sum,sum / 15);
   // //Inorder_NonRecursion(tree);
   // printf("MAX:%d\n", MAXElem(tree));
   // printf("MIN:%d\n", MINElem(tree));
   // system("pause");
   // return OK;
    //Elemtype g[6] = { 10,12,7,8,9,4 };
    //for (int i = 0; i < 6; i++) {
    //    layer = Judge_layer(tree, g[i]);
    //    if (layer == -1) {
    //        //���޸ýڵ㣬�������
    //        printf("��%d�ڵ�\n", g[i]);
    //        continue;
    //    }
    //    printf("%d�ڵ��ڵ�%d��\n", g[i], layer);
    //    sum += layer;
    //}
    //printf("\n\n��ת��\n");
    //LR_Rotate(&tree);
    //for (int i = 0; i < 6; i++) {
    //    layer = Judge_layer(tree, g[i]);
    //    if (layer == -1) {
    //        //���޸ýڵ㣬�������
    //        printf("��%d�ڵ�\n", g[i]);
    //        continue;
    //    }
    //    printf("%d�ڵ��ڵ�%d��\n", g[i], layer);
    //    sum += layer;
    //}
    //printf("\n***%d", GetHeight(tree));
    //printf("������%d�Σ�ƽ�����ҳ���Ϊ%d\n", sum, sum / 15);
    //Inorder_NonRecursion(tree);
    //printf("MAX:%d\n", MAXElem(tree));
    //printf("MIN:%d\n", MINElem(tree));
    system("pause");
    return OK;
}

Status Test2(void) 
{
    LBST t;
    int L[5] = { 5,2,1,6,7 };
    int len = 5;

    creat_LBST(t, L, len);
    visit_LBST(0, t);
    float x = Search_Success_Average_LBST(t, L, len);
    printf("%.2f", x);
    return OK;
}

Status Test3(void)
{
    Elemtype L[10];
    for (int i = 1; i <= 10; i++) {
        L[i - 1] = i;
    }
    BSTptr tree = NULL;
    BSTptr parent = NULL;
    BSTptr p;
    for (int i = 0; i < 10; i++) {
        Insert(&tree, L[i]);
    }
    Inorder_Recursion(tree);
    printf("\n*********************\n");
    p=Get_Delete_Node_And_Parent(tree, 3, &parent);
    tree=Delete(tree, p, parent);
    Inorder_Recursion(tree);
    return OK;
}

Status Command(void)
{
    printf("**********************************************LFD������������ƽ�������**************************************************\n");
    printf("please input your choice:\n");
    printf("1.����BST��(��������洢);2.����BST��(��̬����洢);3.����AVL��;4.���ҵ�ǰ�����Ƿ����ĳ���ڵ�;5.��ƽ�����ҳ���;\n6.���뵥���ڵ�;7.����&ɾ��;8.�������;9.��α���;10.��ӡ���ṹ(BST����ӡ��������);11.�˳�\n");
    printf("************************************************************************************************************************\n");
    printf("Cmd:");
    return OK;
}


BSTptr Init_Node(Elemtype elem) {
    //����һ���ڵ�
    BSTptr p = (BSTptr*)malloc(sizeof(BST));
    if (p == NULL) {
        exit(0);
    }
    p->elem = elem;
    p->Lch = p->Rch = NULL;//���������ÿ�
    return p;
}


Status Search(BSTptr T, Elemtype elem, BSTptr Parent, BSTptr* p)
{//���õݹ���в��ң������ü�¼·��,����Ҫ��¼�丸�ڵ㣬��p�ߵ���ʱ����p�ص�parent���������Ҫ����p������ʹ�ö���ָ��
    if (T == NULL) {
        *p = Parent;
        return FALSE;
    }
    if (T->elem == elem) {//�ҵ�
        *p = T;
        return TRUE;
    }
    else if (T->elem > elem) {//ȥ����������
        return Search(T->Lch, elem, T, p);
    }
    else {//ȥ����������
        return Search(T->Rch, elem, T, p);
    }
}

Status Insert(BSTptr* T, Elemtype elem)
{
    if (*T == NULL) {
        *T = Init_Node(elem);
        return OK;
    }
    BSTptr p;
    if (Search(*T, elem, NULL, &p) == 0) {
        //���ҵ�ǰ���Ƿ���elemֵ�Ľڵ㣬��û�У�������һ��
        BSTptr q = Init_Node(elem);//����һ���ڵ�
        (elem < p->elem) ? (p->Lch = q) : (p->Rch = q);
    }
    else {
        printf("elem--%d�ڵ��Ѿ�����!\n", elem);
    }
    return OK;
}

//
//void Inorder_NonRecursion(BSTptr T)
//{
//    BSTptr p = T;
//    PSTACK mystack;
//    Init(&mystack);
//    while (p && Stack_Empty(&mystack) == 0) {
//        if (p) {//һֱ�����ߣ�����¼·��
//            Stack_Push(&mystack, p->Lch);
//            p = p->Lch;
//        }
//        else {//���ߵ���߾�ͷ������һ��Ԫ�أ�����Ȼ��ʼ����������
//            Stack_Pop(&mystack, p);
//            Vist(p);
//            p = p->Rch;
//        }
//    }
//}

Status Inorder_Recursion(BSTptr T)//ֻ�ñ����������޸��������ݣ����в���ʹ��ָ���ָ��
{
    if (T == NULL) return FALSE;
    Inorder_Recursion(T->Lch);//�������������
    Visit(T);                 //����
    Inorder_Recursion(T->Rch);//�������������
}

Status Levelorder(BSTptr T)
{
    Queue myqueue;
    BSTptr p;
    InitQueue(&myqueue);
    if (T) {
        EnQueue(&myqueue, T);
    }
    while (myqueue.front != myqueue.rear) {
        //���в���
        p = DeQueue(&myqueue);
        Visit(p);
        if (p->Lch) {
            EnQueue(&myqueue, p->Lch);
        }
        if (p->Rch) {
            EnQueue(&myqueue, p->Rch);
        }
    }//while
    return OK;
}


Status Visit(BSTptr T)
{
    printf("%d ", T->elem);
    return OK;
    //���Ϊ���Ԫ�أ�ȥ�����һ������
}

Elemtype MAXElem(BSTptr T)
{
    BSTptr p = T;
    while (p->Rch) p = p->Rch;
    return p->elem;
}

Elemtype MINElem(BSTptr T)
{
    while (T->Lch)T = T->Lch;
    return T->elem;
}

int Judge_layer(BSTptr T, Elemtype elem)
{
    int layer = 1;
    int tag = 0;
    BSTptr p = T;
    while (p) {
        if (p->elem == elem) {
            tag = 1;
            break;
        }
        else if (p->elem > elem) {
            p = p->Lch;
            layer++;
        }
        else {
            p = p->Rch;
            layer++;
        }
    }
    return (tag == 1 ? layer : -1);
}

BSTptr Bulid_AVL(BSTptr T, Elemtype elem)
{
    if (T == NULL) {
        T = (BSTptr*)malloc(sizeof(BST));
        (T)->elem = elem;
        (T)->height = 0;
        (T)->Lch = (T)->Rch = NULL;
    }
    else if (elem < (T)->elem) {
        (T)->Lch = Bulid_AVL((T)->Lch, elem);
        //printf("**%d**%d||", GetHeight(T->Lch), GetHeight(T->Rch));
        if (GetHeight(T->Lch) - GetHeight(T->Rch) == 2) {
            //L?��ת
            if (elem < (T)->Lch->elem) {
                T = LL_Rotate(T);
            }
            else {
                T = LR_Rotate(T);
            }
        }
    }
    else if (elem > (T)->elem) {
        (T)->Rch = Bulid_AVL((T)->Rch, elem);
        if (GetHeight(T->Lch) - GetHeight(T->Rch) == -2) {
            //R?��ת
            if (elem > (T)->Rch->elem) {
                T = RR_Rotate(T);
            }
            else {
                T = RL_Rotate(T);
            }
        }//if
    }//else if
    (T)->height = Max((T)->Lch, (T)->Rch) + 1;
    return T;
}

BSTptr LL_Rotate(BSTptr T) {
    //LL��ת
    BSTptr p = T;
    BSTptr q = (T)->Lch->Rch;
    T = (T)->Lch;
    (T)->Rch = p;
    p->Lch = q;
    return (T);
}

BSTptr LR_Rotate(BSTptr T) {
    //LR��ת
    BSTptr p = T;
    BSTptr q = (T)->Lch;
    T = (T)->Lch->Rch;
    p->Lch = (T)->Rch;
    q->Rch = (T)->Lch;
    (T)->Rch = p;
    (T)->Lch = q;
    return T;
}

BSTptr RL_Rotate(BSTptr T) {
    //RL��ת
    BSTptr p = T;
    BSTptr q = (T)->Rch;
    T = (T)->Rch->Lch;
    p->Rch = (T)->Lch;
    q->Lch = (T)->Rch;
    (T)->Lch = p;
    (T)->Rch = q;
    return T;
}


BSTptr RR_Rotate(BSTptr T) {
    //RR��ת
    BSTptr p = T;
    BSTptr q = (T)->Rch->Lch;
    T = (T)->Rch;
    (T)->Lch = p;
    p->Rch = q;
    return (T);
}
int GetHeight(BSTptr T)
{
    if (T == NULL) return 0;
    return Max(GetHeight(T->Lch), GetHeight(T->Rch)) + 1;
}
int Max(int a, int b)
{
    return a >= b ? a : b;
}
BSTptr Delete(BSTptr T,BSTptr p,BSTptr parent){
    //pΪҪɾ�Ľڵ㣬parentΪ�丸�ڵ�
    BSTptr s, q;
    if (p->Lch == NULL) {
        s = p->Rch;
    }
    else if (p->Rch == NULL) {
        s = p->Lch;
    }
    else {//��������˫���ӽڵ�
        q = p;
        s = p->Lch;
        //��ɾ���ڵ��ֱ�Ӻ��
        while (s->Rch != NULL) {
            q = s;
            s = s->Rch;
        }
        if (p == q) {//û��ִ���Ϸ�ѭ��
            q->Lch = s->Lch;
        }
        else {
            q->Rch = s->Lch;
        }
        p->elem = s->elem;
        free(s);
        return T;
    }
    if (parent == NULL) {
        parent = s;
    }
    else if (parent->Lch == p) {
        parent->Lch = s;
    }
    else {
        parent->Rch = s;
    }
    if (parent == NULL) {
        T = NULL;
    }
    free(p);
    return T;
}

BSTptr Get_Delete_Node_And_Parent(BSTptr T,Elemtype elem, BSTptr* parent)
{
    BSTptr p = T;
    *parent = NULL;
    int tag = 0;
    while (p != NULL) {
        if (elem < p->elem) {
            *parent = p;
            p = p->Lch;
        }
        else if(elem>p->elem){
            *parent = p;
            p = p->Rch;
        }
        else {
            tag = 1;//�����ҵ�
            break;
        }
    }//while
    return tag == 1 ? p : NULL;
}
void Screen_Reveal(BSTptr T)
{
    int height = GetHeight(T);
    int h = height;
    int count = 0;//������
    Queue queue1;
    Queue queue2;                //��ȫ�������Ķ���
    BSTptr p;
    InitQueue(&queue1);
    InitQueue(&queue2);
    if (T) {
        EnQueue(&queue1, T);
        EnQueue(&queue2, T);
    }
    while (queue1.front != queue1.rear) {
        //���в���
        p = DeQueue(&queue1);
        if (p->Lch) {
            EnQueue(&queue1, p->Lch);
            EnQueue(&queue2, p->Lch);
        }
        if (p->Lch == NULL) {
            EnQueue(&queue2, NULL);
        }
        if (p->Rch) {
            EnQueue(&queue1, p->Rch);
            EnQueue(&queue2, p->Rch);
        }
        if (p->Rch == NULL) {
            EnQueue(&queue2, NULL);
        }
    }//while
    /*while (count < pow(2, height) - 1) {
        p = DeQueue(&queue2);
        if (p == NULL) {
            printf(" ��");
        }
        else {
            printf(" %d", p->elem);
        }
        count++;
    }*/

    //���н�����queue2Ϊһ����ȫ������ָ��Ĳ�α���
    printf(" ");
    for (int i = 0; i < height - 1; i++) {
        //���߶�����ӡ,�Ȳ���ӡ���һ��
        for (int k = 0; k < pow(2, h - 1) - 1; k++) {
            printf(" ");
        }
        for (int j = 0; j < pow(2, i); j++) {
            //��ӡÿһ���pow(2,i)���ڵ�
            //�ȴ�ӡpow(2,h-1)-1���ո�

            p = DeQueue(&queue2);
            if (p == NULL) {
                printf("@");

            }
            else {
                printf("%d", p->elem);
            }

            if (i != 0) {
                for (int w = 0; w < ((pow(2, height) - 1) - (pow(2, height - (i + 1)) - 1) * 2 - pow(2, i)) / (pow(2, i) - 1); w++) {
                    printf(" ");
                }
            }


        }//j
        printf("\n ");
        //��ӡб��
        if (h - 2 > 0) {
            for (int a = 0; a < (pow(2, h - 1) + pow(2, h - 2) - 2) / 2; a++) {
                printf(" ");
            }
            for (int c = 0; c < pow(2, i); c++) {
                printf("/");
                for (int b = 0; b < pow(2, h - 2) - 1; b++) {
                    printf(" ");
                }
                printf("\\");
                for (int v = 0; v < (pow(2, h) + pow(2, h - 1) - 2) / 2; v++) {
                    printf(" ");
                }
            }
            printf("\n ");
        }//if
        h--;
    }//i

    /*while (queue2.front != queue2.rear) {
        p = DeQueue(&queue2);
        if (p == NULL) {
            printf("&��");
        }
        else {
            printf("&%d", p->elem);
        }
    }*/
    for (int temp = 0; temp < pow(2, height - 2); temp++) {
        printf("/ \\");
        printf(" ");
    }
    printf("\n");
    for (int temp = 0; temp < pow(2, height - 1); temp++) {
        p = DeQueue(&queue2);
        if (p == NULL) {
            printf("@");
        }
        else {
            printf("%d", p->elem);
        }
        printf(" ");
    }
    printf("\n");
}
//
//void Stack_Init(PSTACK pS)
//{
//    pS->pBottom = (PNODE*)malloc(sizeof(NODE));
//    if (pS->pBottom == NULL)
//    {
//        printf("��̬�ڴ����ʧ�ܣ�\n");
//        exit(-1);
//    }
//    pS->pBottom->pNext = NULL;
//    pS->pTop = pS->pBottom;
//    return;
//}
//
//void Stack_Push(PSTACK pS, BSTptr* T)
//{
//    PNODE pNew;
//    pNew = (PNODE*)malloc(sizeof(NODE));
//    if (NULL == pNew)
//    {
//        printf("��̬�ڴ����ʧ�ܣ�\n");
//        exit(-1);
//    }
//    pNew->data = T;
//    pNew->pNext = pS->pTop;
//    pS->pTop = pNew;
//    return;
//}
//
//int Stack_Empty(PSTACK pS)
//{
//    return pS->pTop == pS->pBottom ? 1 : 0;
//}
//
//void Stack_Pop(PSTACK pS, BSTptr* T)
//{
//    if (Stack_Empty(pS)) printf("ջΪ�գ�\n");
//    else
//    {
//        PNODE temp = pS->pTop;
//        T = temp->data;
//
//        pS->pTop = temp->pNext;
//        free(temp);
//        temp = NULL;
//    }
//    return;
//}


Status InitQueue(Queue* q)
{
    (*q).front = (*q).rear = (Queueptr*)malloc(sizeof(Queue));
    (*q).rear->next = NULL;
    return OK;
}

Status EnQueue(Queue* q, Ptrtype ptr) {
    //β�巨
    Queueptr p = (Queueptr*)malloc(sizeof(Queue));
    if (p == NULL) {
        exit(0);
    }
    p->ptr = ptr;
    p->next = NULL;
    (*q).rear->next = p;
    (*q).rear = p;
    return OK;
}
Ptrtype DeQueue(Queue* q)
{
    Queueptr p = (Queueptr*)malloc(sizeof(Queue));
    p = (*q).front;
    (*q).front = (*q).front->next;
    free(p);
    return((*q).front->ptr);
}

//Status PrintQueue(Queue q)
//{
//    Queueptr p = q.front->next;
//    while (p) {
//        printf("%p ", p->ptr);
//        p = p->next;
//    }
//    return OK;
//}

int Open_File(Elemtype L[])
{
    FILE* fp;
    char c[MAXNODE];//�ַ�������
    int i = 0;      //˳����Ϊ������������
    int t;
    if ((fp = fopen("tree.txt", "r")) == NULL) {
        perror("the file fail to read,please recheck the file's name is 'tree.txt'!");
        //getchar();//��ͣ��ʾ
        system("pause");
        exit(1);
    }
    if (!feof(fp) && !ferror(fp)) {  //����ļ�Ϊ�գ�ֱ����count=0;���⣺����ļ���ȫ�Ƿ����ֵ�Ԫ��?
        (void)fscanf(fp,c);
        if (c == EOF) {
            return i;
        }
    }
    
    while (!feof(fp) && !ferror(fp)) {//�ļ���ȡ������������˳�
        (void)fscanf(fp, "%[^,]%*c", c);//�Զ��ŷָ��ַ�
        L[i] = Convert(c);
        i++;
    }
    fclose(fp);
    return i;
    //ֻ�ǽ����е�����ͳ����һ�£����ܴ�����ͬ��Ԫ�أ���LBST������Ӱ��
}

Elemtype Convert(char* str)
{
    Elemtype n = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        n = n * 10 + (str[i] - '0');
    }
    return n;
}


float Search_Success_Average_LBST(LBST T, Elemtype* L, int count)
{
    int sum = 0;
    int x;
    for (int i = 0; i < count; i++) {
        x = Search_LBST(T, L[i]);
        if (x == -1) {
            printf("û�ҵ�%d!\n", L[i]);
            continue;
        }
        sum += x;
    }
    //float average = (float)sum / (float)count;
    return (float)sum / (float)count;
}

int Search_LBST(LBST T, Elemtype data)
{
    int n = 0;
    int p = 0;
    int tag = 0;
    while (p != null) {
        if (data == T[p].data) {
            tag = 1;
            n += 1;
            break;
        }
        else if (data < T[p].data) {
            p = T[p].Lch;
            n++;
        }
        else {
            p = T[p].Rch;
            n++;
        }

    }
    return tag == 1 ? n : -1;
}


int creat_LBST(LBST t, Elemtype* L, int len) {
    //LBST����
    int last = 0;

    if (len == 0) {
        return last;
    }

    t[0].data = L[0];
    last++;

    for (int i = 1; i < len; i++) {
        int p = 0, q = 0;
        while (p != null && p <= MAXLENGTH) {
            if (t[p].data > L[i]) {
                q = p;
                p = t[p].Lch;
            }
            else if(t[p].data<L[i]){
                q = p;
                p = t[p].Rch;
            }
            else {
                continue;
            }
        }//while

        if (t[q].data > L[i]) {
            t[q].Lch = last;
        }
        else {
            t[q].Rch = last;
        }
        p = last;
        t[p].data = L[i];
        last++;
    }//for
    return last;
}

int insert_LBST(LBST t, Elemtype elem,int len)
{
    int i = 0;  //�±��ƶ�
    int j;
    int tag = 0;//�ж�t���Ƿ���elem
    while (i != null) {
        if (t[i].data > elem) {
            j = i;
            i = t[i].Lch;
        }
        else if (t[i].data < elem) {
            j = i;
            i = t[i].Rch;
        }
        else {
            tag = 1;
            break;
        }//while
    }
    if (tag == 0) {
        elem < t[j].data ? (t[j].Lch = len-1) : (t[j].Rch = len-1);
        t[len-1].data = elem;
    }
    return tag;
}

Status visit_LBST(int R, LBST t) {
    //LBST�������
    if (R == null) {
        return OK;
    }
    else {
        visit_LBST(t[R].Lch, t);
        printf("%d ", t[R].data);
        visit_LBST(t[R].Rch, t);
    }
}

Status Delete_LBST(LBST T, int p, int parent) {
    //pΪҪɾ���Ľڵ��±�parentΪ�丸�ڵ�
    int q, s;
    if (T[p].Lch == null) s = T[p].Rch;
    else if (T[p].Rch == null) s = T[p].Lch;
    else {
        q = p;
        s = T[p].Lch;
        while (T[s].Rch != null) {
            q = s;
            s = T[s].Rch;
        }
        if (p == q) {
            T[q].Lch = T[s].Lch;
        }
        else {
            T[q].Rch = T[s].Lch;
        }
        T[p].data = T[s].data;
        T[s].data = null;
        return OK;
    }//else

    if (parent == null) {
        //���ڵ�
        parent = s;
    }
    else if (T[parent].Lch == p) {
        T[parent].Lch = s;
    }
    else {
        T[parent].Rch = s;
    }
    T[p].data = null;
    return OK;
}


int Get_LBST_Node_And_Parent(LBST T, Elemtype data, int* parent)
{
    int p = 0;
    *parent = null;
    while (p != null) {
        if (data < T[p].data) {
            *parent = p;
            p = T[p].Lch;
        }//if
        else if (data > T[p].data) {
            *parent = p;
            p = T[p].Rch;
        }//else if
        else {
            break;
        }
    }//while

    return p;
}

//
//int Count_Leaf_Node(BSTptr T)
//{
//    if (T == NULL)
//    {
//        return 0;
//    }
//    if (T->Lch == NULL && T->Rch == NULL) 
//    {
//        return 1;
//    }
//    return Count_Leaf_Node(T->Lch) + Count_Leaf_Node(T->Rch);
//}
//
//void Swap_Ltree_Rtree(BSTptr T) 
//{
//    if (T == NULL) {
//        return;
//    }
//    if (T->Lch == NULL && T->Rch == NULL) {
//        return;
//    }
//
//    BSTptr temp = T->Lch;
//    T->Lch = T->Rch;
//    T->Rch = temp;
//
//    return Swap_Ltree_Rtree(T->Lch);
//    return Swap_Ltree_Rtree(T->Rch);
//}
//
//
//Status Test4(void)
//{
//    Elemtype L[10] = { 27,16,51,38,75 };
//    BSTptr tree = NULL;
//    for (int i = 0; i < 5; i++) {
//        Insert(&tree, L[i]);
//    }
//    //int sum = Count_Leaf_Node(tree);
//    //printf("%d", sum);
//    Swap_Ltree_Rtree(tree);
//    Inorder_Recursion(tree);
//}
