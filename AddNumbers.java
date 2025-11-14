class AddNumbers {
    // Step 1: Declare native method
    public native int add(int a, int b);

    // Step 2: Load DLL
    static {
        System.loadLibrary("AddLib"); // Loads AddLib.dll
    }

    // Step 3: Test the native function
    public static void main(String[] args) {
        AddNumbers obj = new AddNumbers();
        int result = obj.add(10, 20);
        System.out.println("Addition = " + result);
    }
}
