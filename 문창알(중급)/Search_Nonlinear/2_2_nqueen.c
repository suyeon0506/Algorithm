/*
�����п��� ��Ʈ��ŷ ������ n - queen problem�� �����ϴ�.
�� ������ n*nü�� �����ǿ� n���� queen�� ���� �������� ���ϵ��� ��ġ�ϴ� ���
�� ã�Ƴ��� �����̴�.
�Ʒ� �׸��� n�� 4�� ��� queen�� ���� �������� ���ϰ� ��ġ�� �� ���� ��Ÿ��
��.
ü���� ũ�� �� queen�� ���� ��Ÿ���� n�� �Է¹޾Ƽ� ���� �������� ���ϵ���
��ġ�ϴ� �� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
���� n�� �Է����� ���´�.(3 <= n <= 9)
���
���� �ٸ� �� ����� ���� ����Ѵ�.
*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int visited[10][10];//ü����, ���� 1�� �ٲ�� �κп��� ���� �� ���´�
int copy[10][10];//visited�� ���� ���¸� ������ ���纻
int num = 0;//�� ����� ��
int top = -1;
typedef struct Stack{
	int i, j;
}Stack;
Stack stack[10];

void copy_visited()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			copy[i][j] = visited[i][j];
	}
}

void push(int i, int j)
{
	top++;
	stack[top].i = i;
	stack[top].j = j;
}

void pop(int i, int j)
{
	stack[top].i = 0;
	stack[top].j = 0;
	top--;

	for (int k = 0; k < 10; k++)
	{
		for (int h = 0; h < 10; h++)
			visited[k][h] = copy[k][h];
	}//���� visited ���·� ��������
}

void ban(int i, int j)
{
	//queen�� ���� ��ġ (i,j)�� �޾Ƽ� �̵��� �� �ִ� ��, �� �ٸ� queen�� �� �� ���� �ڸ��� 1�� ǥ���Ѵ�

	int k;
	
	visited[i][j] = 1;

	for (k = 1; ; k++)
	{
		if (i - k < 0 || j - k < 0)
			break;

		visited[i - k][j - k] = 1;
	}//NW����

	for (k = 1; ; k++)
	{
		if (i - k < 0)
			break;

		visited[i - k][j] = 1;
	}//N����

	for (k = 1; ; k++)
	{
		if (i - k < 0 || j + k >= n)
			break;

		visited[i - k][j + k] = 1;
	}//NE ����

	for (k = 1; ; k++)
	{
		if (j + k >= n)
			break;

		visited[i][j + k] = 1;
	}//E����

	for (k = 1; ; k++)
	{
		if (i + k >= n || j + k >= n)
			break;

		visited[i + k][j + k] = 1;
	}//SE����

	for (k = 1; ; k++)
	{
		if (i + k >= n)
			break;

		visited[i + k][j] = 1;
	}//S����

	for (k = 1; ; k++)
	{
		if (i + k >= n || j - k < 0)
			break;

		visited[i + k][j - k] = 1;
	}//SW����

	for (k = 1; ; k++)
	{
		if (j - k < 0)
			break;

		visited[i][j - k] = 1;
	}//W����
}

void main(void)
{
	int i = 0, j = 0;
	int pop_flag = 0;
	int break_flag = 0;

	scanf("%d", &n);

	while ((i < n) && (j < n))
	{
		copy_visited();

		if (pop_flag != 1)
		{
			ban(i, j);
			push(i, j);
		}

		if (top == n - 1)
		{
			num++;//����� ���� �ϳ� �߰�
			break;
		}
				
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (visited[i][j] == 0)
				{
					pop_flag = 0;
					break_flag = 1;
					break;
				}
				else
					pop_flag = 1;
			}
			if (break_flag == 1)
			{
				break_flag = 0; //�����·� ��������
				break;
			}
		}

		if (pop_flag == 1)
		{
			i = stack[top].i;
			j = stack[top].j;
			pop(i, j);
			visited[i][j] = 1;
		}
	}

	printf("%d\n", num);
}
*/
////////////////////////////������� �˰��� ���� �� ����///////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 9

int n;
int col[MAX], inc[MAX+MAX], dec[MAX+MAX]; //�˰��� ����� �迭��
int num = 0; //��ü ����� ��

void dfs(int k)
{
	if (k >= n)
	{
		num++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (col[i] == 0 && inc[k + i] == 0 && dec[k - i + (n - 1)] == 0)
		{
			col[i] = inc[k + i] = dec[k - i + (n - 1)] = 1;
			dfs(k + 1);
			col[i] = inc[k + i] = dec[k - i + (n - 1)] = 0;//��Ʈ��
		}
	}
}

void main(void)
{
	scanf("%d", &n);
	dfs(0);
	printf("%d\n", num);
}

//queen�� �ϳ��� �࿡ �ݵ�� �ϳ��� ��ġ�ؾ� �ϹǷ� ���� �������ΰ� ���� �ݺ����� ������.
//�迭���� ���� �밢���� ��ġ�� ��� ���� ��, ���� ������ Ư���� �̿��Ѵ�.
//��ͷ� ���� ������ ������� �� �����ؾ� �Ѵ�.
//��Ʈ�� ���� �� �����ϱ�.