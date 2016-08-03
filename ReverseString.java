public class ReverseString {
	public static void main(String[] args) {
		System.out.println(reverseString("hello world"));
	}

	public static String reverseString(String s) {
    	char tmp;
		StringBuilder sb = new StringBuilder(s);
		for (int i=0; i<s.length()/2; i++) {
			tmp = s.charAt(s.length() - 1 - i);
			sb.setCharAt(i, tmp);
			sb.setCharAt(s.length() - 1 - i, s.charAt(i));
		}
		return sb.toString();
	}
}
