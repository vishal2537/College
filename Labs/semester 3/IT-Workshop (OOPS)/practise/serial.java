import java.io.File;
import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

//serialization

class save implements Serializable{
    int i;
}

public class serial {
    public static void main(String[] args) throws Exception {
        save obj = new save();
        obj.i = 4;
        File f = new File("input.txt");
        FileOutputStream fos = new FileOutputStream(f);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(obj);
    }
}
