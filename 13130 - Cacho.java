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
		int T = in.nextInt();
		for(int cs = 1 ; cs <= T ; cs++){
			solver.solve(cs, in, out);
		}
		out.close();
	}

	static class Task {

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			short first = in.nextShort();
			boolean ok = true;
			for(int i = 0 ; i < 4 ; i++){
				short second = in.nextShort();
				if(second - first != 1){
					ok = false;
				}
				first = second;
			}
			out.println(ok ? "Y" : "N");
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
		
		public short nextShort() {
			return Short.parseShort(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
}
