import java.io.*;
import java.net.*;
import java.util.*;
class RarpClient{
  public static void main(String args[]){
    try{
      Scanner sc = new Scanner(System.in);
      Socket clsct=new Socket("localhost",2000);
      DataInputStream din=new DataInputStream(clsct.getInputStream());
      DataOutputStream dout=new DataOutputStream(clsct.getOutputStream());
      System.out.println("Enter the Physical Address(MAC):");
      String str1=sc.nextLine();
      dout.writeUTF(str1);
      String str=din.readUTF();
      if(!str.equals("Address not Found"))
        System.out.println("The Logical Address(IP) is: "+str);
      else
        System.out.println(str);
      clsct.close();
      sc.close();
    }catch (Exception e){
      System.out.println(e);
    }
  }
}