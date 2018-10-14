/*
�����̴� ������ ���� ��� ����Ǿ� ������ �� ���� �� ������ �δ����� ��� ��
�̶�� ����� �߰��Ͽ���.
�����̴� �޻꿡 ��� �δ����� ��� �� �������� �ñ�������. �����̴� Ư�� ��
�� �̿��Ͽ� �޻��� �δ��� ���� ��� ��Ÿ�� ������ ���� �� �־���.
�� ������ ���簢���̰� ���� ���� ������ 0 �Ǵ� 1�� ǥ���Ѵ�. 0�� ���̰� 1��
�δ��� ���� ��Ÿ����. 1�� �����¿�� ����Ǿ� ������ �� ������ �δ����� ���
������ ������ �� �ִ�.
[�׸� 2]�� [�׸� 1]�� �δ��� ���� ��ȣ�� ���� ���̴�. Ư���Կ� ���� �����͸� ��
�¹޾� �δ��� ���� ���� ����ϰ�, �� �δ��� ���� ũ�⸦ ������������ �����Ͽ�
����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù ��° �ٿ� ����, ������ ũ�⸦ ��Ÿ���� n�� �Էµȴ�.(n�� 30������ �ڿ���)
�� ��° �ٺ��� n�ٿ� ���ļ� n���� 0�� 1�� �������� ���еǾ� �Էµȴ�.
���
ù° �ٿ� �δ��� ���� ���� ����Ѵ�. ��° �ٺ��� �� �δ��� ���� ũ�⸦ ����
�������� �� �ٿ� �ϳ��� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int n;
int arr[MAX][MAX];
int top = -1;
int visited[MAX][MAX];
int num = 0; //�δ��� �� ��
int size = 0; //�δ��� �� ũ��
int size_arr[(MAX*MAX)/2]; //�δ��� �� ũ��� ������ �迭
int index = 0; //size_arr ���� �ε��� ����
int flag = 0; //�� �ϳ��� �� ������������ 1�� ǥ��

typedef struct Stack{
	int i, j;
}Stack;

Stack stack[MAX];

void push(int i, int j)
{
	if (top == MAX * MAX)
		printf("The stack is full!\n");
	else
	{
		top++;
		stack[top].i = i;
		stack[top].j = j;
	}
}

Stack pop(int i, int j)
{
	if (top == -1)
	{
		num++; //�� �ϳ� ���� ������
		flag = 1;
		size_arr[index++] = size;
		size = 0; //�� ũ�� �ʱ�ȭ
	}
	else
	{
		size++;
		return stack[top--];
	}
}

void dfs(int i, int j)
{
	if (visited[i - 1][j] == 0 && arr[i - 1][j] == 1)//��
	{
		i = i - 1;
		visited[i][j] = 1;
		push(i , j);
		dfs(i , j);
	}
	else if (visited[i + 1][j] == 0 && arr[i + 1][j] == 1)//�Ʒ�
	{
		i = i + 1;
		visited[i][j] = 1;
		push(i, j);
		dfs(i, j);
	}
	else if (visited[i][j - 1] == 0 && arr[i][j - 1] == 1)//����
	{
		j = j - 1;
		visited[i][j] = 1;
		push(i, j);
		dfs(i, j);
	}
	else if (visited[i][j + 1] == 0 && arr[i][j + 1] == 1)//������
	{
		j = j + 1;
		visited[i][j] = 1;
		push(i, j);
		dfs(i, j);
	}
	else
	{
		pop(i, j);
		i = stack[top].i;
		j = stack[top].j;
		if (flag == 1)
		{
			flag = 0;
			return;
		}
		else
			dfs(i, j);
	}
}

int compare(void *first, void *second)
{
	if (*(int*)first < *(int*)second)
		return 1;
	else if (*(int*)first > *(int*)second)
		return -1;
	else
		return 0;
}//�������� ������ ����

void main(void)
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == 0 && arr[i][j] == 1)
			{
				visited[i][j] = 1;
				push(i, j);
				dfs(i, j);
			}
		}
	}

	printf("%d\n", num);
	qsort(size_arr, index, sizeof(int), compare);//�������� ����; ����Ʈ ���̺귯�� �����

	for (int i = 0; i < index; i++)
		printf("%d\n", size_arr[i]);
}

//���� �̿��� ��� : ������ �̷�ã�� ���α׷����� �̿��� dfs�� �����. �׷��� �� ���� Ǫ�� ����� ����. dfs���� elseif ���� if�� ���� ���� �ʿ���� ��͸����� �����ϴ� ; ���� �˰��� ����
//�߰� : ��͸��� while(1) break;�� ����!! ��ʹ� �ð�,���� ���� ��Ƹ���. �̷ζ� dfs������ ��� �ƴ� �ݺ��� �����
/*
flood fill : �̷��� ���� �ܿ��� ���� ���Ǵ� �˰���; �ϳ��� ��Ʈ(����)�� �� �� ���ڸ� �����ؼ� �ٲ㼭 �迭�� ä��� ���.
���� ��� ù��° ���� dfs�� ���鼭 �迭�� 1�� 2�� �ٲ��ִ� ����. �̶� dfs���� else if�� ���� ���� if�� �Ἥ 4������ ��� ä���. �ٽ� ���ƿͼ� Ž���� �ʿ� ����! -> ���� �ʿ���� ��͸����� ����
�ϳ��� ���� ��� 2�� ä��� ���� �� ���� 1�ΰ����� ���� �� ���� ������ 3���� ä�������� ������ �� �ִ�.
���� �� ���ڵ��� index�� Ȱ���Ͽ� 2��° ���� ũ�⸦ size_arr[2]�� �����ϴ� ������ �� �� �ִ�.
*/