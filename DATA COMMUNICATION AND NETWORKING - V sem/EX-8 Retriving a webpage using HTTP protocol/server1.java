import  java.io.*;
import java.net.*;
import java.util.*;
import java.io.*;
import java.net.*;
public class server1{
    public static void main(String[] args){
    try {
     ServerSocket ss = new ServerSocket(3000);
     Socket s = ss.accept();
     DataInputStream dis = new DataInputStream(s.getInputStream());
     String str = (String) dis.readUTF();
     URL url = new URL(str);
      
      Scanner sc = new Scanner(url.openStream());
      
      StringBuffer sb = new StringBuffer();
      while(sc.hasNext()) {
         sb.append(sc.next());
      
      }
        String result = sb.toString();
        result = result.replaceAll(">", ">\n");
        DataOutputStream  dos= new DataOutputStream(s.getOutputStream());
        dos.writeUTF(result);
         
     dos.flush();
     dos.close();
     s.close();
     sc.close();
     ss.close();
    } catch (Exception e) {
        System.out.println(e);
    }
    }
}