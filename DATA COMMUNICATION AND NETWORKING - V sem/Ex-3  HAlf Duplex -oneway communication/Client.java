import java.net.Socket;
import java.io.*;

public class Client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			System.out.println("Client Strats...");
			Socket soc = new Socket("localhost",9806);
			System.out.println("Enter Text:");
			BufferedReader userInput = new BufferedReader (new InputStreamReader(System.in));
			String str = userInput.readLine();
			PrintWriter out = new PrintWriter(soc.getOutputStream(),true);
			out.println(str);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}

}
