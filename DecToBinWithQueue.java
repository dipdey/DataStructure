/*
Author: Dipankar Dey
print in binary
*/
import java.util.LinkedList;
import java.util.Queue;

public class DecToBinWithQueue {

	private static void printBin(int n) {
		Queue<String> queue = new LinkedList<>();
		queue.add("1");
		while (0 != n) {
			String b = queue.remove();
			queue.add(b.concat("0"));
			queue.add(b.concat("1"));
			System.out.println(b);
			n--;
		}
	}

	public static void main(String[] args) {
		printBin(10);
	}

}
