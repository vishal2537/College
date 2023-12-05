import java.util.Scanner;

class Account {

    private int accountNumber;
    private String accountType;
    private String serviceBranchIFSC;
    private float minimumBalance;
    private float availableBalance;
    private int customerID;
    private String customerName;
    private static int totalAccountCreated;

    Account() {
    }

    public int getAccNumber() {
        return accountNumber;
    }

    public int getCustomerID() {
        return customerID;
    }

    public void setDetails(int account_number, String account_type, float minimum_balance, String IFSC,
            String acccount_holder, float balance, int customer_Id, int total_number_of_account) {

        accountNumber = account_number;
        accountType = account_type;
        minimumBalance = minimum_balance;
        serviceBranchIFSC = IFSC;
        availableBalance = balance;
        customerName = acccount_holder;
        customerID = customer_Id;
        totalAccountCreated = total_number_of_account;
    }

    public void updateDetails(int account_number, String account_type, float minimum_balance, String IFSC,
            String acccount_holder, float balance,
            int customer_Id) {

        if (accountNumber == account_number) {

            accountType = account_type;
            minimumBalance = minimum_balance;
            serviceBranchIFSC = IFSC;
            availableBalance = balance;
            customerName = acccount_holder;
            customerID = customer_Id;
        }
    }

    public void getDetails(int account_number) {
        if (account_number == accountNumber) {

            System.out.println("    ACCOUNT NUMBER : " + accountNumber);
            System.out.println("    ACCOUNT TYPE : " + accountType);
            System.out.println("    MINIMUM BALANCE : " + minimumBalance);
            System.out.println("    IFSC : " + serviceBranchIFSC);
            System.out.println("    AVAILABLE BALANCE : " + availableBalance);
            System.out.println("    Customer Name : " + customerName);
            System.out.println("    Customer ID : " + customerID);
        }
    }

    public void Deposit(int account_number, float amount) {
        if (account_number == accountNumber) {
            availableBalance += amount;
            System.out.println("SUCCESSFULLY DEPOSIT TO ACCOUNT NUMBER : " + accountNumber);
        }
    }

    public void Withdraw(int account_number, float amount) {

        if (account_number == accountNumber) {
            if (availableBalance >= amount + minimumBalance) {
                availableBalance -= amount;
                System.out.println("SUCCESSFULLY WITHDRAW FROM ACCOUNT NUMBER : " + accountNumber);
            } else {
                System.out.println("INSUFFICIENT BALANCE !!");
            }
        }
    }

    public float getBalance(int account_number) {
        if (account_number == accountNumber)
            return availableBalance;
        else {
            return -1;
        }
    }

    // public static int totalAccount() {
    public int totalAccount() {
        return totalAccountCreated;
    }
}

public class banking_application_system {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        Account[] array;
        array = new Account[1000];

        int i = 0;
        while (true) {
            System.out.println("\n!!      WELCOME TO MV BANK      !!\n");
            System.out.println(
                    "\t0 - setDetails()\n\t1 - UpdateDetails()\n\t2 - getDetails()\n\t3 - Deposit()\n\t4 - Withdraw()\n\t5 - getBalance()\n\t6 - totalAccount()\n\t7 - Exit()\n");

            System.out.println("ENTER YOUR CHIOCE :");
            int ch = input.nextInt();

            if (ch == 0) {

                System.out.println("Enter Account details for Person " + (i + 1));

                System.out.println("Enter Account Number");
                int account_number = input.nextInt();
                for (int j = 0; j < array.length; j++) {
                    if (array[j] != null && array[j].getAccNumber() == account_number) {

                        System.out.println("ACCOUNT NUMBER ALREADY EXIST !!");
                        System.out.println("ENTER ACCOUNT NUMBER AGAIN :");
                        account_number = input.nextInt();
                    }
                }
                input.nextLine();

                System.out.println("ENTER ACCOUNT TYPE : ");
                String account_type;
                while (true) {
                    System.out.printf(
                            "\nCHOOSE ACCOUNT TYPE :\n\t1. SAVINGS ACCOUNT\n\t2. CURRENT ACCOUNT\n\t3. SALARY ACCOUNT\n");
                    int ac = input.nextInt();
                    if (ac == 1) {
                        account_type = "SAVING ACCOUNT";
                        break;
                    } else if (ac == 2) {
                        account_type = "CURRENT ACCOUNT";
                        break;
                    } else if (ac == 3) {
                        account_type = "SALARY ACCCOUNT";
                        break;
                    } else {
                        System.out.println("Invalid Choice");
                    }
                }

                System.out.println("ENTER MINIMUM BALANCE :     ");
                float minimum_balance = input.nextFloat();

                System.out.println("ENTER CUSTOMER NAME :   ");
                input.nextLine();
                String account_holder = input.nextLine();

                System.out.println("ENTER TOTAL BALANCE :   ");
                float balance = input.nextInt();

                System.out.println("ENTER IFSC CODE :   ");
                input.nextLine();
                String ifsc = input.nextLine();

                System.out.println("ENTER CUSTOMER ID :     ");
                int customer_Id = input.nextInt();
                input.nextLine();
                array[i] = new Account();
                array[i].setDetails(account_number, account_type, minimum_balance, ifsc, account_holder, balance,
                        customer_Id, i + 1);
                i++;

            } else if (ch == 1) {

                System.out.println("ENTER ACCOUNT NUMBER : ");
                int account_number = input.nextInt();
                input.nextLine();

                System.out.println("ENTER ACCOUNT TYPE : ");
                String account_type;
                while (true) {
                    System.out.printf(
                            "\nCHOOSE ACCOUNT TYPE :\n\t1. SAVINGS ACCOUNT\n\t2. CURRENT ACCOUNT\n\t3. SALARY ACCOUNT\n");
                    int ac = input.nextInt();
                    if (ac == 1) {
                        account_type = "SAVING ACCOUNT";
                        break;
                    } else if (ac == 2) {
                        account_type = "CURRENT ACCOUNT";
                        break;
                    } else if (ac == 3) {
                        account_type = "SALARY ACCCOUNT";
                        break;
                    } else {
                        System.out.println("Invalid Choice");
                    }
                }

                System.out.println("ENTER MINIMUM BALANCE : ");
                float minimum_balance = input.nextFloat();

                System.out.println("ENTER CUSTOMER NAME : ");
                input.nextLine();
                String account_holder = input.nextLine();

                System.out.println("ENTER TOTAL BALANCE : ");
                float balance = input.nextInt();

                System.out.println("ENTER IFSC CODE : ");
                input.nextLine();
                String ifsc = input.nextLine();

                System.out.println("ENTER CUSTOMER ID : ");
                int customer_Id = input.nextInt();
                input.nextLine();

                for (int j = 0; j < i; j++) {
                    if (array[j] != null)
                        array[j].updateDetails(account_number, account_type, minimum_balance, ifsc, account_holder,
                                balance, customer_Id);
                }

            } else if (ch == 2) {
                System.out.println("ENTER ACCOUNT NUMBER TO GET DETAILS : ");
                int account_number = input.nextInt();
                for (int j = 0; j < i; j++) {
                    array[j].getDetails(account_number);
                }

            } else if (ch == 3) {
                System.out.println("ENTER ACCOUNT NUMBER : ");
                int account_number = input.nextInt();
                System.out.println("ENTER AMOUNT TO BE DEPOSITED : ");
                int amount = input.nextInt();
                for (int j = 0; j < i; j++) {
                    array[j].Deposit(account_number, amount);
                }

            } else if (ch == 4) {
                System.out.println("ENTER ACCOUNT NUMBER : ");
                int account_number = input.nextInt();
                System.out.println("ENTER AMOUNT TO BE WITHDRAW : ");
                int amount = input.nextInt();
                for (int j = 0; j < i; j++) {
                    array[j].Withdraw(account_number, amount);
                }
            } else if (ch == 5) {
                System.out.println("ENTER ACCOUNT NUMBER TO CHECK BALANCE : ");
                int account_number = input.nextInt();
                for (int j = 0; j < i; j++) {
                    float balance = array[j].getBalance(account_number);
                    if (balance != -1) {
                        System.out.println("Available Balance : " + array[j].getBalance(account_number));
                    }

                }
            } else if (ch == 6) {
                System.out.println("TOTAL NUMBER OF ACCOUNT OPENED IN THE BANK : " + array[0].totalAccount());
            } else if (ch == 7) {
                break;
            }
        }
        input.close();
    }
}
