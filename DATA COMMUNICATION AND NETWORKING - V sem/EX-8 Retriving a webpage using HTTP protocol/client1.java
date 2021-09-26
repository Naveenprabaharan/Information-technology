import java.io.IOException;
import java.net.URL;
import java.util.Scanner;
import java.io.*;
import java.net.*;
public class client1 {
   public static void main(String args[]) throws IOException {
    try {
        Socket soc = new Socket ("localhost",3000);
        Scanner sc = new Scanner(System.in);
        DataInputStream dis = new DataInputStream(soc.getInputStream());
        System.out.println("Enter the URL");
     String str = sc.nextLine();      
     DataOutputStream  dos= new DataOutputStream(soc.getOutputStream());
     dos.writeUTF(str);
     str=(String)dis.readUTF();

     System.out.println("The HTML source code of the Web page is \n"+ str);
     
      
        soc.close();    
    } catch (Exception e) {
        System.out.println(e);
    }        
    //   System.out.println("Contents of the web page: "+result);
   }
}