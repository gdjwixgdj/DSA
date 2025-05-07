import java.util.Scanner;

class Merge
{
	public static void MergeSort(int arr[], int left, int mid, int right)
	{
		int n1 = mid - left + 1;
		int n2 = right - mid;

		int L[] = new int[n1];
		int R[] = new int[n2];

		for(int i = 0; i < n1; i++)
			L[i] = arr[left + i];
		for(int j = 0 ; j < n2 ; j++)
			R[j] = arr[mid + 1 + j];

		int i = 0, j = 0, k = left;
		while(i < n1 && j < n2)
		{
			if(L[i] <= R[j])
				arr[k++] = L[i++];
			else
				arr[k++] = R[j++];
		}
		while(i < n1)
			arr[k++] = L[i++];
		while(j < n2)
			arr[k++] = R[j++];
	}

	public static void merge(int arr[], int left, int right)
	{
		if(left < right)
		{
			int mid = (left+right)/2;
			merge(arr, left, mid);
			merge(arr, mid + 1, right);

			MergeSort(arr, left, mid, right);
		}
	}

	public static void printArray(int arr[])
	{
		for(int i : arr)
			System.out.print(i + " ");
		System.out.println();
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("How many elements : ");
		int n = sc.nextInt();
		int arr[] = new int[n];

		System.out.println("Enter elements");
		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		System.out.print("Before Sorting : ");
		printArray(arr);

		merge(arr, 0, arr.length-1);

		System.out.print("After Sorting : ");
		printArray(arr);
	}
}
