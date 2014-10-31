/*
Author: Dipankar Dey
From given +ve integer array, find the largest number multiple of 3, comprising the digits
in the array.
*/
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class LargestMultipleOfThree {
	private static void sortReverseOrder(int[] arr) {
		Arrays.sort(arr);
		int s = 0;
		int e = arr.length - 1;
		while (s < e) {
			int t = arr[s];
			arr[s] = arr[e];
			arr[e] = t;
			s++;
			e--;
		}
	}

	private static int[] dumpQueueToArray(Queue<Integer> q0, Queue<Integer> q1,
			Queue<Integer> q2) {
		int aux[] = new int[q0.size() + q1.size() + q2.size()];
		int i = 0;
		while (!q0.isEmpty()) {
			aux[i++] = q0.remove().intValue();
		}
		while (!q1.isEmpty()) {
			aux[i++] = q1.remove().intValue();
		}
		while (!q2.isEmpty()) {
			aux[i++] = q2.remove().intValue();
		}
		return aux;
	}

	private static int[] copyArray(int arr[]) {
		int[] newArr = new int[arr.length];
		for (int i = 0; i < newArr.length; i++) {
			newArr[i] = arr[i];
		}
		return newArr;
	}

	public static int[] getLargest(int[] arr2) {
		int arr[] = copyArray(arr2);
		int[] aux = null;
		int sum = 0;

		Queue<Integer> queue0 = new LinkedList<>();
		Queue<Integer> queue1 = new LinkedList<>();
		Queue<Integer> queue2 = new LinkedList<>();

		Arrays.sort(arr);
		for (int i = 0; i < arr.length; i++) {
			sum += arr[i];
			if ((arr[i] % 3) == 0) {
				queue0.add(arr[i]);
			} else if ((arr[i] % 3) == 1) {
				queue1.add(arr[i]);
			} else {
				queue2.add(arr[i]);
			}
		}

		if ((sum % 3) == 0) {

		} else if ((sum % 3) == 1) {
			if (!queue1.isEmpty()) {
				queue1.remove();
			} else if (!queue2.isEmpty() && queue2.size() >= 2) {
				queue2.remove();
				queue2.remove();
			} else {
				// Not possible
			}
		} else if ((sum % 3) == 2) {
			if (!queue2.isEmpty()) {
				queue2.remove();
			} else if (!queue1.isEmpty() && queue1.size() >= 2) {
				queue1.remove();
				queue1.remove();
			} else {
				// Not possible
			}
		} else {
			// Not possible
		}

		aux = dumpQueueToArray(queue0, queue1, queue2);
		sortReverseOrder(aux);

		return aux;
	}

	public static void main(String[] args) {
		int[] arr = {1,3,4,5};
		arr = getLargest(arr);
		for(int i=0; i<arr.length; i++) {
			System.out.print(arr[i]);
		}
		System.out.println();
	}

}
