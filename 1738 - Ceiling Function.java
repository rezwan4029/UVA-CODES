import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class TreeNode {

	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int _v) {
		val = _v;
		left = right = null;
	}
}

public class Main {

	static String route = "";

	public static TreeNode insertBST(TreeNode root, int key) {
		if (root == null) {
			return new TreeNode(key);
		}
		if (root.val < key) {
			root.right = insertBST(root.right, key);
		} else {
			root.left = insertBST(root.left, key);
		}
		return root;
	}

	static void inorderTraverse(TreeNode root) {
		if (root != null) {
			route += "l";
			inorderTraverse(root.left);
			route += "r";
			inorderTraverse(root.right);
		}
	}

	public static void main(String args[]) {
		Scanner ob = new Scanner(System.in);
		while (ob.hasNext()) {
			int n = ob.nextInt();
			int k = ob.nextInt();
			Set<String> ans = new HashSet<>();
			for (int i = 0; i < n; i++) {
				TreeNode root = null;
				for (int j = 0; j < k; j++) {
					int val = ob.nextInt();
					root = insertBST(root, val);
				}
				route = "";
				inorderTraverse(root);
				ans.add(route);
			}
			System.out.println(ans.size());
		}
		ob.close();
	}
}
