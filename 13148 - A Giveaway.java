import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String args[]) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {

		int ans[] = { 1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809,
				7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121 };

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int N = in.nextInt();
			if (N == 0) {
				return;
			}
			boolean special = false;
			for (int i = 0; i < ans.length; i++) {
				if (ans[i] == N) {
					special = true;
					break;
				}
			}
			out.println(special ? "Special" : "Ordinary");
			solve(testNumber, in, out);
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
}
