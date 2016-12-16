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
		
		final int SZ = 5;
		
		static class Foot{
			int row;
			boolean reverse;
			Foot(int _row, boolean _reverse){
				row = _row;
				reverse = _reverse;
			}
		}
		
		private Foot getRowOfFoot(char grid[][]) {
			for (int i = 0; i < SZ; i++) {
				for (int j = 0; j < SZ; j++) {
					if(grid[i][j] == '>' || grid[i][j] == '<'){
						return new Foot(i, (grid[i][j] == '<'));
					}
				}
			}
			return null;
		}
		
		boolean isNoBall(char grid[][], Foot foot){
			int line = 0;
			for(int j = 0 ; j < SZ; j++){
				if(grid[foot.row][j] == '|'){
					line = j;
					break;
				}
			}
			if(!foot.reverse){
				for(int j = line + 1 ; j < SZ; j++){
					if(grid[foot.row][j] == '>'){
						return true;
					}
				}
				return false;
			}else{
				for(int j = line + 1 ; j < SZ; j++){
					if(grid[foot.row][j] == '<'){
						return false;
					}
				}
				return true;
			}
		}
		
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			char grid[][] = new char[SZ][SZ];
			for(int i = 0 ; i < SZ ; i++){
				grid[i] = in.next().toCharArray();
			}
			Foot foot = this.getRowOfFoot(grid);
			out.println("Case " + testNumber + ": " + (isNoBall(grid, foot) ? "No Ball" : "Thik Ball"));
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
