import java.io.*;
import java.net.*;
import java.util.*;
class ArpClient{
  public static void main(String args[]){
    try{
      Scanner sc = new Scanner(System.in);
      Socket clsct=new Socket("localhost",2000);
      DataInputStream din=new DataInputStream(clsct.getInputStream());
      DataOutputStream dout=new DataOutputStream(clsct.getOutputStream());
      System.out.println("Enter the Logical address(IP):");
      String str1=sc.nextLine();
      dout.writeUTF(str1);
      String str=din.readUTF();
      if(!str.equals("Address not Found"))
        System.out.println("The Physical Address is: "+str);
      else
        System.out.println(str);
      clsct.close();
      sc.close();
    }catch (Exception e){
      System.out.println(e);
    }
  }
}