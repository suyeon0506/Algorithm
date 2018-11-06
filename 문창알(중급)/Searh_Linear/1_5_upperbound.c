/*
n���� �̷���� ���� ���տ��� ���ϴ� �� k���� ū ���� ó������ �����ϴ� ��ġ
�� ã���ÿ�.
��, �ԷµǴ� ������ ������������ ���ĵǾ� ������, ���� ���� ���� �� ������ ��
�ִ�.
�Է�
ù° �ٿ� �� ���� n, ��° �ٿ� n���� ������ �������� ���еǾ� �Էµȴ�. ��°
�ٿ��� ã���� �ϴ� �� k�� �Էµȴ�.
(��, 2 <= n <= 1,000,000, �� ������ ũ��� 100,000,000�� ���� �ʴ´�.)
���
ã���� �ϴ� ������ ��ġ�� ����Ѵ�. ���� ��� ���Ұ� k���� ������ n+1�� ���
�Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, k;
int arr[1000001];

void find_upper(int left, int right)
{
	int middle = (left + right) / 2;

	if (left >= right)
	{
		printf("%d\n", middle + 1);
		return;
	}

	if (k >= arr[middle])//�迭�� ���� ���� ���� �� �����Ƿ� ��ȣ �ʿ�. ���Ѽ��̹Ƿ� ���⿡ �־���.
		find_upper(middle + 1, right);
	else if (k < arr[middle])
		find_upper(left, middle);
}

void main(void)
{
	int i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &k);
	find_upper(0, n);
}