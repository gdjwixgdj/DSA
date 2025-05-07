import java.util.Scanner;

public class ShellSort
{
    public static void shellsort(int arr[])
    {
        int n = arr.length;
        for(int gap = n/2; gap > 0; gap /= 2)
        {
            for(int i = gap; i < n; i++)
            {
                int temp = arr[i];
                int j = i;
                while(j >= gap && arr[j - gap] > temp)
                {
                    arr[j] = arr[j-gap];
                    j -= gap;
                }
                arr[j] = temp;
            }
        }
    }
    public static void printArray(int arr[])
    {
        for(int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    public static void main(String...s)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Number of elements in array : ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.print("Enter array elements : ");
        for(int i = 0 ; i < n ; i++)
            arr[i] = sc.nextInt();

        System.out.print("Before Sorting : ");
        printArray(arr);

        shellsort(arr);

        System.out.print("After Sorting : ");
        printArray(arr);
    }
}
