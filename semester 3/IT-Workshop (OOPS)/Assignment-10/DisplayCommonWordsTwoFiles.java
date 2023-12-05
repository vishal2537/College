import java.util.*;
import java.io.*;

class wordAndLine {
    String word;
    int line;
    public wordAndLine(String word, int line) {
        this.word = word;
        this.line = line;
    }
}

public class DisplayCommonWordsTwoFiles {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("input two files");
        } else {
            try {
                ArrayList<wordAndLine> firstFile = new ArrayList<>();
                ArrayList<wordAndLine> secondFile = new ArrayList<>();

                File first = new File(args[0]);
                File second = new File(args[1]);

                Scanner firstScanner = new Scanner(first);
                Scanner secondScanner = new Scanner(second);

                int i = 0;
                while (firstScanner.hasNextLine()) {
                    String[] line = firstScanner.nextLine().split(" ");
                    for (String word : line) {
                        firstFile.add(new wordAndLine(word, i));
                    }
                    i++;
                }
                firstScanner.close();
                i = 0;
                while (secondScanner.hasNextLine()) {
                    String[] line = secondScanner.nextLine().split(" ");
                    for (String word : line) {
                        secondFile.add(new wordAndLine(word, i));
                    }
                    i++;
                }
                secondScanner.close();

                for (i = 0; i < firstFile.size(); i++) {
                    wordAndLine firstFileWord = firstFile.get(i);
                    for (int k = 0; k < secondFile.size(); k++) {
                        wordAndLine secondFileWord = secondFile.get(k);
                        if (secondFileWord.word.equals(firstFileWord.word) && !secondFileWord.word.equals("")) {
                            System.out.println(secondFileWord.word + " : length " + secondFileWord.word.length()
                                    + " , appeared in " + (firstFileWord.line + 1) + "th line of " + args[0] + " and "
                                    + (secondFileWord.line + 1)
                                    + "th line in " + args[1]);
                            break;
                        }
                    }
                }
            } catch (FileNotFoundException fnfe) {
                System.out.println("File not found!");
                System.exit(0);
            }

        }
    }
}


