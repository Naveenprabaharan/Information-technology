import java.net.Socket;
import java.io.*;
public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			System.out.println("Client starts...");
			Socket soc = new Socket("localhost",9806);
			BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter Text To sent 'SERVER' : ");
			String str = userInput.readLine();
			PrintWriter out = new PrintWriter(soc.getOutputStream(),true);
			out.println(str);
			
//			data read from client:
			BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream()));
			String str1 = in.readLine();
			System.out.println("Server message recived! \nServer message: "+str1);
		}
		catch(Exception e) {
			e.printStackTrace();
		}

	}

}
