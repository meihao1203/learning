/**
 * C 语言: AVL树
 *
 * @author skywang
 * @date 2013/11/07
 */
#include <stdio.h>
#include "avltree.h"
#include<iostream>
using namespace std;
static int arr[]= {3,2,1,4,5,6,7,10,9,8};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

void main()
{
    int i,ilen;
    AVLTree root=NULL;
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        root = avltree_insert(root, arr[i]);
    }

    inorder_avltree(root);
    printf("\n");
    destroy_avltree(root);
	system("pause");
}