/*
n���� �̷���� ���� ���տ��� ���ϴ� ���� ��ġ�� ã���ÿ�.
��, �ԷµǴ� ������ ������������ ���ĵǾ� ������, ���� ���� ����.
�Է�
ù �ٿ� �� ���� n�� �Էµȴ�.
��° �ٿ� n���� ������ �������� ���еǾ� �Էµȴ�.
��° �ٿ��� ã���� �ϴ� ���� �Էµȴ�.
(��, 2 <= n <= 1,000,000 , �� ������ ũ��� 100,000,000�� ���� �ʴ´�.)
���
ã���� �ϴ� ������ ��ġ�� ����Ѵ�. ������ -1�� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, num;
int A[1000001];
//num�� �������� ���°� ����. �׷��� �Ѱ����� �ʾƵ� �Ǵϱ�.

void find_seq(int n, int num)
{
	int i;
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		if (num == A[i])
		{
			printf("seq, %d\n", i+1);
			flag = 1;
			break;
		}
	}

	if (flag == 0)
		printf("seq, -1\n");
}

void find_bin(int left, int right, int num)
{
	int middle = (left + right) / 2;

	if ((middle == left - 1) || (middle == right + 1))
	{
		printf("bin, -1\n");
		return;
	}//base ó���ε� �̰ͺ��ٴ� if(left>right) return;�� ���

	if (A[middle] == num)
	{
		printf("bin, %d\n", middle+1);//print �ٷ� �������� middle+1 ���� �����ϴ� ������ �ϸ� ���� base������ -1 �����ϸ� �ȴ�. void���� return;�� �Ҿ���
		return;
	}
	else if (A[middle] > num)
		find_bin(left, middle-1, num);
	else if (A[middle] < num)
		find_bin(middle+1, right, num);
}
void main(void)
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	scanf("%d", &num);

	find_seq(n, num);
	find_bin(0, n-1, num);
}