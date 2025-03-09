package validatorLib;

public class ValidatorLib {
    static {
        System.loadLibrary("ValidatorLibrary"); // Load the native library
    }

    public native long createValidator();
    public native void destroyValidator(long validatorPtr);
    public native boolean validate(long validatorPtr);

    public static void main(String[] args) {
        ValidatorLib lib = new ValidatorLib();
        long validator = lib.createValidator();
        System.out.println("Validator instance: " + validator);

        boolean isValid = lib.validate(validator);
        System.out.println("Validation result: " + isValid);

        lib.destroyValidator(validator);
    }
}
