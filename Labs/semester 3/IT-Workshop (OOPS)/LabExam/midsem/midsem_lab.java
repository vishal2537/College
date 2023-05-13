import java.sql.Date;
import java.util.ArrayList;
import java.util.Scanner;

class User {
    private int userID;
    private String name;
    private String dateOfBirth;
    private String Address;
    private String PAN;

    public User() {

    }

    public User(int userID, String name, String dateOfBirth, String address, String pAN) {
        this.userID = userID;
        this.name = name;
        this.dateOfBirth = dateOfBirth;
        Address = address;
        PAN = pAN;
    }

}

class Admin extends User {
    private String dateOfJoining;
    private int salary;
    private String permissibleOperations;

    public Admin() {
    }

    public Admin(int userID, String name, String dateOfBirth, String address, String pAN, String dateOfJoining,
            int salary, String permissibleOperations) {
        super(userID, name, dateOfBirth, address, pAN);
        this.dateOfJoining = dateOfJoining;
        this.salary = salary;
        this.permissibleOperations = permissibleOperations;
    }

}

class General extends User {
    private String dateOfJoining;
    private int salary;
    private int dutyHourPerDay;

    public General() {
    }

    public General(int userID, String name, String dateOfBirth, String address, String pAN, String dateOfJoining,
            int salary, int dutyHourPerDay) {
        super(userID, name, dateOfBirth, address, pAN);
        this.dateOfJoining = dateOfJoining;
        this.salary = salary;
        this.dutyHourPerDay = dutyHourPerDay;
    }
}

class Item {
    protected int itemCode;
    private int price;
    private int AvailableQty;

    public int getItemCode() {
        return itemCode;
    }

    public int getPrice() {
        return price;
    }

    public int getAvailableQty() {
        return AvailableQty;
    }

    public Item() {
    }

    public Item(int itemCode, int price, int availableQty) {
        this.itemCode = itemCode;
        this.price = price;
        AvailableQty = availableQty;
    }

    public boolean checkItemCode(int itemCode) {
        return this.itemCode == itemCode;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public void setQuantity(int availableQty) {
        AvailableQty = availableQty;
    }

    public void modifyStock(int quantity) {
        AvailableQty -= quantity;
    }

    public void display() {
        System.out.println("ITEMCODE: " + itemCode);
        System.out.println("PRICE: " + price);
        System.out.println("AvailableQty: " + AvailableQty);
    }
}

class FoodItem extends Item {
    private String dateOfExpiry;

    public FoodItem() {
    }

    public FoodItem(int itemCode, int price, int availableQty, String dateOfExpiry) {
        super(itemCode, price, availableQty);
        this.dateOfExpiry = dateOfExpiry;
    }

    public boolean checkItemCode(int itemCode) {
        return this.itemCode == itemCode;
    }

    public void display() {
        super.display();
        System.out.println("DATEOFEXPIRY: " + dateOfExpiry);
    }
}

class NonFoodItem extends Item {

    private int returnCount;

    public NonFoodItem() {
    }

    public NonFoodItem(int itemCode, int price, int availableQty, int returnCount) {
        super(itemCode, price, availableQty);
        this.returnCount = returnCount;
    }

    public boolean checkItemCode(int itemCode) {
        return this.itemCode == itemCode;
    }

    public void display() {
        super.display();
        System.out.println("DATEOFEXPIRY: " + returnCount);
    }
}

class Sell {

    private String dateOfSell;
    private int itemCode;
    private int quantity;
    private int totalAmount;

    public Sell() {
    }

    public Sell(String dateOfSell, int itemCode, int quantity, int totalAmount) {
        this.dateOfSell = dateOfSell;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.totalAmount = totalAmount;
    }

}

class Return {
    private String dateOfReturn;
    private int itemCode;
    private int quantity;
    private int returnAmount;

    public Return() {
    }

    public Return(String dateOfReturn, int itemCode, int quantity, int returnAmount) {
        this.dateOfReturn = dateOfReturn;
        this.itemCode = itemCode;
        this.quantity = quantity;
        this.returnAmount = returnAmount;
    }

}

public class midsem_lab {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        ArrayList<Item> arrayitem = new ArrayList<Item>();
        ArrayList<FoodItem> arrayfooditem = new ArrayList<FoodItem>();
        ArrayList<NonFoodItem> arraynonfooditem = new ArrayList<NonFoodItem>();
        ArrayList<Sell> arraysellitem = new ArrayList<Sell>();
        ArrayList<Return> arrayreturn = new ArrayList<Return>();

        while (true) {
            System.out.println("1. ADMIN \n2.GENERAL\n");
            int ch1 = input.nextInt();
            if (ch1 == 1) {
                System.out.println("1. ADDNEW \n2. DELETESTOCK \n3. MODIFYSTOCK \n");
                int ch2 = input.nextInt();
                if (ch2 == 1) {
                    System.out.print("ITEMCODE: ");
                    int itemCode = input.nextInt();
                    System.out.print("PRICE: ");
                    int price = input.nextInt();
                    System.out.print("AVAILABLEQUANTITY: ");
                    int availableQty = input.nextInt();
                    System.out.println("1. FOODITEM \n2. Non FOODITEM\n");
                    int ch3 = input.nextInt();
                    input.nextLine();
                    if (ch3 == 1) {
                        System.out.print("DATEOFEXPIRY: ");
                        String dateOfExpiry = input.nextLine();
                        FoodItem fi = new FoodItem(itemCode, price, availableQty, dateOfExpiry);
                        arrayfooditem.add(fi);
                        arrayitem.add(fi);
                    } else {
                        System.out.print("RETURNCOUNT: ");
                        int returnCount = input.nextInt();
                        NonFoodItem nfi = new NonFoodItem(itemCode, price, availableQty, returnCount);
                        arraynonfooditem.add(nfi);
                        arrayitem.add(nfi);
                    }
                } else if (ch2 == 2) {
                    System.out.print("ITEMCODE: ");
                    int itemCode = input.nextInt();
                    System.out.println("1. FOODITEM \n2. NONFOODITEM");
                    int ch3 = input.nextInt();
                    if (ch3 == 1) {
                        for (FoodItem fi : arrayfooditem) {
                            if (fi.checkItemCode(itemCode) == true) {
                                arrayfooditem.remove(fi);
                                arrayitem.remove(fi);
                                break;
                            }
                        }
                    } else {
                        for (NonFoodItem nfi : arraynonfooditem) {
                            if (nfi.checkItemCode(itemCode) == true) {
                                arrayfooditem.remove(nfi);
                                arrayitem.remove(nfi);
                                break;
                            }
                        }
                    }
                } else if (ch2 == 3) {
                    System.out.println("1.PRICE \n2. AVAILQUANTITY");
                    int ch3 = input.nextInt();
                    System.out.print("ITEMCODE: ");
                    int itemCode = input.nextInt();
                    if (ch3 == 1) {
                        System.out.println("ENTER NEW PRICE");
                        int price = input.nextInt();
                        for (Item it : arrayitem) {
                            if (it.checkItemCode(itemCode) == true) {
                                it.setPrice(price);
                                break;

                            }
                        }
                    } else {
                        System.out.println("AVAILQUIANTITY");
                        int availableQty = input.nextInt();
                        for (Item it : arrayitem) {
                            if (it.checkItemCode(itemCode) == true) {
                                it.setQuantity(availableQty);
                                break;
                            }
                        }
                    }

                }

            } else {
                System.out.println("1.SELLITEM \n2. RETURNITEM \n3. DISPLAYSTOCK \n4. DISPLAYSELL");
                int ch2 = input.nextInt();
                if (ch2 == 1) {
                    System.out.println("DATEOFSELL : ");
                    input.nextLine();
                    String dateOfSell = input.nextLine();
                    System.out.print("ITEMCODE: ");
                    int itemCode = input.nextInt();
                    Item it = null;
                    for (Item i : arrayitem) {
                        if (i.checkItemCode(itemCode) == true)
                            it = i;
                    }
                    if (it == null)
                        continue;
                    System.out.print("QUANTITY: ");
                    int quantity = input.nextInt();
                    while (it.getAvailableQty() < quantity) {
                        System.out.println("ENTER AGAIN !!");
                        quantity = input.nextInt();
                    }
                    int totalAmount = it.getPrice() * quantity;
                    Sell si = new Sell(dateOfSell, itemCode, quantity, totalAmount);
                    arraysellitem.add(si);
                    it.modifyStock(quantity);
                } else if (ch2 == 2) {
                    System.out.print("DATEOFRETURN: ");
                    input.nextLine();
                    String dateOfReturn = input.nextLine();
                    System.out.print("ITEMCODE: ");
                    int itemCode = input.nextInt();
                    Item it = null;
                    for (Item i : arrayitem) {
                        if (i.checkItemCode(itemCode) == true && i instanceof NonFoodItem)
                            it = i;
                        else if (i.checkItemCode(itemCode) == true && i instanceof FoodItem) {
                            System.out.println("COANNOT RETURN ");
                        }
                    }
                    if (it == null)
                        continue;
                    System.out.print("QUANTITY: ");
                    int quantity = input.nextInt();
                    while (it.getAvailableQty() < quantity) {
                        System.out.println("ENTER AGAIN :!!");
                        quantity = input.nextInt();
                    }
                    int returnAmount = it.getPrice() * quantity;
                    Return si = new Return(dateOfReturn, itemCode, quantity, returnAmount);
                    arrayreturn.add(si);
                    it.modifyStock(quantity);
                } else if (ch2 == 3) {
                    System.out.print("ITEMCODE: ");
                    int itemCode = input.nextInt();
                    for (Item it : arrayitem) {
                        if (it.checkItemCode(itemCode) == true) {
                            it.display();
                            break;
                        }
                    }
                }
            }
        }
    }
}
