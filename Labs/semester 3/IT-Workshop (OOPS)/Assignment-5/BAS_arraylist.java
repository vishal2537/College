import java.util.*;

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

    public int check_accountno(int id) {
        if (id == accountNumber) {
            return 1;
        }
        return 0;
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

    public void compare(Account ac1, Account ac2) {
        float bal_1 = ac1.getBalance(ac1.accountNumber);
        float bal_2 = ac2.getBalance(ac2.accountNumber);
        if (bal_1 > bal_2) {
            ac1.getDetails(ac1.accountNumber);
        } else {
            ac2.getDetails(ac2.accountNumber);
        }
    }

    public static int totalAccount() {
        return totalAccountCreated;
    }

    public static void removeacc(ArrayList<Account> arr, int j) {
        arr.remove(j);
        totalAccountCreated--;
    }
}

public class BAS_arraylist {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Account> arr = new ArrayList<Account>(1000);
        // ArrayList<Account> a =new ArrayList<>()
        int i = 0;
        while (true) {
            System.out.println("\n!!      WELCOME TO MV BANK      !!\n");
            System.out.println(
                    "\t0 - setDetails()\n\t1 - UpdateDetails()\n\t2 - getDetails()\n\t3 - Deposit()\n\t4 - Withdraw()\n\t5 - getBalance()\n\t6 - totalAccount()\n\t7 - Compare()\n\t8 - Delete()\n\t9 - Exit()\n");

            System.out.println("ENTER YOUR CHIOCE :");
            int ch = input.nextInt();
            if (ch == 0) {
                System.out.println("Enter Account details for Person " + (i + 1));
                System.out.println("Enter Account Number");
                int account_number = input.nextInt();
                for (int j = 0; j < arr.size(); j++) {
                    if (arr.get(j) != null && arr.get(j).getAccNumber() == account_number) {
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
                
                // array[i] = new Account();
                Account obj = new Account();
                obj.setDetails(account_number, account_type, minimum_balance, ifsc, account_holder, balance,
                        customer_Id, i + 1);
                arr.add(obj);
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
                        account_type = "SALARY ACCOUNT";
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
                    if (arr.get(j) != null)
                        arr.get(j).updateDetails(account_number, account_type, minimum_balance, ifsc, account_holder,
                            balance, customer_Id);
                }

            } else if (ch == 2) {
                System.out.println("ENTER ACCOUNT NUMBER TO GET DETAILS : ");
                int account_number = input.nextInt();
                for (int j = 0; j < i; j++) {
                    arr.get(j).getDetails(account_number);
                }

            } else if (ch == 3) {
                System.out.println("ENTER ACCOUNT NUMBER : ");
                int account_number = input.nextInt();
                System.out.println("ENTER AMOUNT TO BE DEPOSITED : ");
                int amount = input.nextInt();
                for (int j = 0; j < i; j++) {
                    arr.get(j).Deposit(account_number, amount);
                }

            } else if (ch == 4) {
                System.out.println("ENTER ACCOUNT NUMBER : ");
                int account_number = input.nextInt();
                System.out.println("ENTER AMOUNT TO BE WITHDRAW : ");
                int amount = input.nextInt();
                for (int j = 0; j < i; j++) {
                    arr.get(j).Withdraw(account_number, amount);
                }
            } else if (ch == 5) {
                System.out.println("ENTER ACCOUNT NUMBER TO CHECK BALANCE : ");
                int account_number = input.nextInt();
                for (int j = 0; j < i; j++) {
                    float balance = arr.get(j).getBalance(account_number);
                    if (balance != -1) {
                        System.out.println("Available Balance : " + arr.get(j).getBalance(account_number));
                    }

                }
            } else if (ch == 6) {
                System.out.println("TOTAL NUMBER OF ACCOUNT OPENED IN THE BANK : " + Account.totalAccount());
            }

            else if (ch == 7) {
                System.out.println("ENTER ACCOUNT NUMBER TO COMPARE : ");
                int ac1 = input.nextInt();
                int ac2 = input.nextInt();
                Account acc1 = null, acc2 = null;
                for (Account J : arr) {
                    if (J == null) {
                        continue;
                    }
                    if (ac1 == J.getAccNumber()) {
                        acc1 = J;
                    }
                }
                for (Account J : arr) {
                    if (J == null) {
                        continue;
                    }
                    if (ac2 == J.getAccNumber()) {
                        acc2 = J;
                    }
                }
                if (acc1 != null && acc2 != null) {
                    acc1.compare(acc1, acc2);
                }
            } else if (ch == 8) {
                System.out.println("ENTER ACCOUNT NUMBER TO DELETE : ");
                int id = input.nextInt();
                int flag = 0, j;

                for (j = 0; j < i; j++) {
                    if (arr.get(j) == null)
                        continue;
                    else {
                        flag = arr.get(j).check_accountno(id);
                        if (flag == 1) {
                            break;
                        }
                    }
                }
                Account.removeacc(arr, j);
                i--;
                System.out.println("SUCCESSFULLY DELETE DATA !!");
            }

            else if (ch == 9) {
                break;
            }
        }
        input.close();
    }
}