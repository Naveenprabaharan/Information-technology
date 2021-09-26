import java.io.*;
import java.net.*;
import java.util.*;
class RarpServer{
  public static void main(String args[]){
    try{
      	ServerSocket obj=new ServerSocket(2000);
      	Socket obj1=obj.accept();
		DataInputStream din=new DataInputStream(obj1.getInputStream());
		DataOutputStream dout=new DataOutputStream(obj1.getOutputStream());
		String str=din.readUTF();
		String ip[]={"165.165.80.80","165.165.79.1"};
		String mac[]={"2C:54:91:88:C9:E3","8A:BC:E3:FA:C9:E3"};
		int flag = 1;
		for(int i=0;i<ip.length;i++){
		  if(str.equals(mac[i])){
		    dout.writeUTF(ip[i]+'\n');
		    flag = 0;
		    break;
		  }
		}
		if(flag == 1){
			dout.writeUTF("Address not Found");
		}           
        obj.close();             
    }catch(Exception e){
      System.out.println(e);
    }
  }
}