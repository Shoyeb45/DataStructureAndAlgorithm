package HashMapInJava;

import java.util.Scanner;

public class Implementation {
    public static void main(String[] args) {
        Scanner sc = new  Scanner(System.in);
        HashMap<String, Integer> mp = new HashMap<>();
        mp.insert("Stud1", 19);
        mp.insert("Stud2", 18);
        System.out.println("Size " + mp.size());
        System.out.println(mp.get("Stud1"));
        System.out.println(mp.get("stud1"));  

        mp.delKey("Stud1");
        System.out.println("Size " + mp.size());
        System.out.println("Empty: " + mp.empty());
        
        mp.insert("Stud3", 21);
        System.out.println(mp.contains("Stud3"));
        System.out.println("Size " + mp.size());
        mp.delKey("Stud3");
        mp.delKey("Stud2");
        System.out.println("Empty: " + mp.empty());

        sc.close();
    
    }
}