/*
n���� �̷���� ���� ���տ��� ���ϴ� �� k �̻��� ���� ó������ �����ϴ� ��ġ
�� ã���ÿ�.
��, �ԷµǴ� ������ ������������ ���ĵǾ� ������, ���� ���� ���� �� ������ ��
�ִ�.
�Է�
ù° �ٿ� �� ���� n�� �Էµȴ�.
��° �ٿ� n���� ������ �������� ���еǾ� �Էµȴ�.
��° �ٿ��� ã���� �ϴ� �� k�� �Էµȴ�.
(��, 2 <= n <= 1,000,000 , �� ������ ũ��� 100,000,000�� ���� �ʴ´�.)
���
ã���� �ϴ� ������ ��ġ�� ����Ѵ�. ���� ��� ���Ұ� k���� ������ n+1�� ���
�Ѵ�.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1000001];

void find(int n, int k)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] >= k)
		{
			printf("%d\n", i+1);
			return;
		}
		else if (a[0] > k)
		{
			printf("1\n");
			return;
		}
	}
	printf("%d\n", n + 1);
}

void find_binary(int left, int right, int k)
{
	int middle = (left + right) / 2;

	if (left >= right)//= �� �־�� �Ѵ�. ��!
	{
		printf("%d\n", middle + 1);
		return;
	}

	if (k > a[middle])
		find_binary(middle + 1, right, k);
	else if (k < a[middle])
		find_binary(left, middle, k); //���Ѽ��̹Ƿ� k�� �� ���� ���� middle ���� �����Ͽ� �ٽ� Ž���ؾ��Ѵ�.
}

void main(void)
{
	int n, k;
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d", &k);
	find(n, k);
	find_binary(0, n, k);
}
