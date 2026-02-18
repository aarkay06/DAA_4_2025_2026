public class Method {
    public void print(float a, int b) {
        System.out.print(a + b);
    }

    public void print(int a, float b) {
        System.out.print(a + b);
    }

    public static void main(String[] args) {
        Method method = new Method();
        method.print(10, 'd');
    }
}