//Nicholas Ang
//CS326 Hw 8
//Java Color Sampler

//Creates ColorApp Action Handler Class file, ColorApp drawing tester class file, color app class file, color app window destroyer class file, color app list handler class file
//Use a colors.txt file with 11 different colors like the example
//Compiled using javac ColorApp.java
//Run using java ColorApp


import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;
import java.io.*;

//Color App Application
public class ColorApp extends JFrame
{
	//Protected Fields
	protected JList<String> listColors;
	protected DrawingTester drawTest;
	protected JLabel labelR;
	protected JLabel labelG;
	protected JLabel labelB;
	protected JTextField tfR;
	protected JTextField tfG;
	protected JTextField tfB;
	protected int i;
	protected int x;
	protected int y;
	protected int z;
	protected static String[] colors = new String[11];
	protected static int[] R = new int[11];
	protected static int[] G = new int[11];
	protected static int[] B = new int[11];
	protected JButton buttonSave;
	protected JButton buttonReset;

	protected JButton buttonP1;
	protected JButton buttonP2;
	protected JButton buttonP3;
	protected JButton buttonM1;
	protected JButton buttonM2;
	protected JButton buttonM3;
	
	//Main, works at startup of program
	public static void main(String argv []) throws IOException
	{
		//File IO
		FileInputStream istream = new FileInputStream("colors.txt");  
		InputStreamReader reader = new InputStreamReader(istream); 
		StreamTokenizer tokens = new StreamTokenizer(reader); 
		
		//Read in values to arrays of RED, GREEN, and BLUE
		for(int k=0; tokens.nextToken() != tokens.TT_EOF; k++) 
		{  
		colors[k] = (String) tokens.sval; 
		tokens.nextToken(); 
		R[k] = (int) tokens.nval; 
		tokens.nextToken(); 
		G[k] = (int) tokens.nval; 
		tokens.nextToken(); 
		B[k] = (int) tokens.nval;   
		} 
		istream.close();
		new ColorApp("Color Sampler");
	}

	//Color App class
	public ColorApp(String title)
	{
		super(title);
		//Set Title of application to Color Sampler
		super.setTitle("Color Sampler");
		//scale window
		setBounds(100, 100, 500, 500);
		addWindowListener(new WindowDestroyer());            
		getContentPane().setLayout(null);
		drawTest = new DrawingTester();
		labelR = new JLabel("RED");
		labelG = new JLabel("GREEN");
		labelB = new JLabel("BLUE");

		//Start at first color index
		int x = R[0];
		int y = G[0];
		int z = B[0];

		//Add buttons and text fields to window, connect with action handler
		tfR = new JTextField(String.valueOf(x));
		tfG = new JTextField(String.valueOf(y));
		tfB = new JTextField(String.valueOf(z));
		listColors = new JList<>();
		listColors.addListSelectionListener(new ListHandler());
		buttonSave = new JButton("Save");
		buttonReset = new JButton("Reset");
		buttonP1 = new JButton("+");
		buttonP2 = new JButton("+");
		buttonP3 = new JButton("+");
		buttonM1 = new JButton("-");
		buttonM2 = new JButton("-");
		buttonM3 = new JButton("-");
		buttonSave.addActionListener(new ActionHandler());  
		buttonReset.addActionListener(new ActionHandler());
		buttonP1.addActionListener(new ActionHandler()); 
		buttonP2.addActionListener(new ActionHandler()); 
		buttonP3.addActionListener(new ActionHandler()); 
		buttonM1.addActionListener(new ActionHandler()); 
		buttonM2.addActionListener(new ActionHandler()); 
		buttonM3.addActionListener(new ActionHandler()); 

		//Scale where in the application is each component
		getContentPane().add(listColors);
		listColors.setBounds(300,10,150,400);
		getContentPane().add(drawTest);
		drawTest.setBounds(10,10,250,150);
		getContentPane().add(labelR);
		labelR.setBounds(50,300,40,30);
		getContentPane().add(labelG);
		labelG.setBounds(50,330,40,30);
		getContentPane().add(labelB);
		labelB.setBounds(50,360,40,30);
		getContentPane().add(tfR);
		tfR.setBounds(100,300,40,30);
		getContentPane().add(tfG);
		tfG.setBounds(100,330,40,30);
		getContentPane().add(tfB);
		tfB.setBounds(100,360,40,30);
		getContentPane().add(buttonSave);
		buttonSave.setBounds(25,400,75,50);
		getContentPane().add(buttonReset);
		buttonReset.setBounds(125,400,75,50);
		getContentPane().add(buttonP1);
		getContentPane().add(buttonP2);
		getContentPane().add(buttonP3);
		getContentPane().add(buttonM1);
		getContentPane().add(buttonM2);
		getContentPane().add(buttonM3);
		buttonP1.setBounds(150,300,45,30);
		buttonP2.setBounds(150,330,45,30);
		buttonP3.setBounds(150,360,45,30);
		buttonM1.setBounds(200,300,45,30);
		buttonM2.setBounds(200,330,45,30);
		buttonM3.setBounds(200,360,45,30);

		//Prevents people from editing the text box, only manipulated by button
		tfR.setEditable(false);
		tfG.setEditable(false);
		tfB.setEditable(false);

		//Create list and start at index 0
		listColors.setListData(colors);
		listColors.setSelectedIndex(0);
		setVisible(true);

	}

	//List Handler class to create lists
	private class ListHandler implements ListSelectionListener 
	{      
		public void valueChanged(ListSelectionEvent e)
		{	
 		if ( e.getSource() == listColors )
     			if ( !e.getValueIsAdjusting() )
     			{
				//Select component in list, sets the color of sample and text fields to correct color
				i = listColors.getSelectedIndex();
				String s = (String) listColors.getSelectedValue();
				System.out.println("Position " + i + " selected: " +s);
				tfR.setText(String.valueOf(R[i]));
				tfG.setText(String.valueOf(G[i]));
				tfB.setText(String.valueOf(B[i]));
				setTitle("Color Sampler");
				repaint();
     			}
		}
	}	

	//Action Handler Class to handle button implementation
	private class ActionHandler implements ActionListener
	{      
		public void actionPerformed(ActionEvent e)
		{
			//If button save is clicked, saves current values to the array
			//Reset title name
			if ( e.getSource() == buttonSave )
			{
			R[i] = Integer.parseInt(tfR.getText());
			G[i] = Integer.parseInt(tfG.getText());
			B[i] = Integer.parseInt(tfB.getText());

			setTitle("Color Sampler");
			}
			//If button reset is clicked, swap back to old values in the array
			//Reset title name
			else if ( e.getSource() == buttonReset )
			{
			x = R[i];
			y = G[i];
			z = B[i];
			tfR.setText(String.valueOf(x));
			tfG.setText(String.valueOf(y));
			tfB.setText(String.valueOf(z));
			repaint();
			setTitle("Color Sampler");
			}
			//If Plus button 1 is clicked, add 5 to x and reflect in RED value
			//Change title name to "Color Sampler*"
			else if ( e.getSource() == buttonP1 )
			{
			int x = Integer.parseInt(tfR.getText());
			if(x<255 && x>=0)
			{
				x = x + 5;
				tfR.setText(String.valueOf(x));
				repaint();
			}
			setTitle("Color Sampler*");
			}
			//If Plus button 2 is clicked, add 5 to y and reflect in GREEN value
			//Change title name to "Color Sampler*"
			else if ( e.getSource() == buttonP2 )
			{
			int y = Integer.parseInt(tfG.getText());
			if(y<255 && y>=0)
			{
				y = y + 5;
				tfG.setText(String.valueOf(y));
				repaint();
			}
			setTitle("Color Sampler*");
			}
			//If Plus button 3 is clicked, add 5 to z and reflect in BLUE value
			//Change title name to "Color Sampler*"
			else if ( e.getSource() == buttonP3 )
			{
			int z = Integer.parseInt(tfB.getText());
			if(z<255 && z>=0)
			{
				z = z + 5;
				tfB.setText(String.valueOf(z));
				repaint();
			}
			setTitle("Color Sampler*");
			}
			//If Minus button 1 is clicked, subtract 5 to x and reflect in RED value
			//Change title name to "Color Sampler*"
			else if ( e.getSource() == buttonM1 )
			{
			int x = Integer.parseInt(tfR.getText());
			if(x<=255 && x>0)
			{
				x = x - 5;
				tfR.setText(String.valueOf(x));
				repaint();
			}
			setTitle("Color Sampler*");
			}
			//If Minus button 2 is clicked, subtract 5 to y and reflect in GREEN value
			//Change title name to "Color Sampler*"
			else if ( e.getSource() == buttonM2 )
			{
			int y = Integer.parseInt(tfG.getText());
			if(y<=255 && y>0)
			{
				y = y - 5;
				tfG.setText(String.valueOf(y));
				repaint();
			}
			setTitle("Color Sampler*");
			}
			//If Minus button 3 is clicked, subtract 5 to z and reflect in BLUE value
			//Change title name to "Color Sampler*"
			else if ( e.getSource() == buttonM3 )
			{
			int z = Integer.parseInt(tfB.getText());
			if(z<=255 && z>0)
			{
				z = z - 5;
				tfB.setText(String.valueOf(z));
				repaint();
			}
			setTitle("Color Sampler*");
			}
		}
	}	
	
	//Window Destroyer Class
	private class WindowDestroyer extends WindowAdapter 
	{      
		//Upon exit, write all saved values to file
		public void windowClosing(WindowEvent e) 
		{    
			outputFile();
			System.exit(0);  
		}                                                             
	}  

	//DrawingTester Class    
	private class DrawingTester extends JComponent
	{
		//Paint colors the background of a rectangle with values from the text fields
		public void paint(Graphics g)
		{
			Dimension d = getSize();
			String s1 = tfR.getText();
			String s2 = tfG.getText();
			String s3 = tfB.getText();
			x = Integer.parseInt(s1);
			y = Integer.parseInt(s2);
			z = Integer.parseInt(s3);
			g.setColor(new Color(x,y,z));
			g.fillRect(1, 1, d.width-2, d.height-2);
		}
	}   
    
	//Output File function
	public void outputFile()
	{
		//If able to write, write every color value into the file in the array
		try
		{
			//Open colors.txt and add name, red value, green value, blue value to file
			FileOutputStream ostream = new FileOutputStream("colors.txt");
			PrintWriter writer = new PrintWriter(ostream);
			for(int j = 0; j < 11; j++) 
			{  
				String s = colors[j]; 
				int n = R[j]; 
				int m = G[j]; 
				int l = B[j]; 
				writer.println(s + "  " + n + " " + m + " " + l);  
			}
			writer.flush();  
			ostream.close();
			System.out.println("File written.");  
		}
		//Otherwise report an error
		catch(IOException errorX)
		{
			System.err.println("ERROR: " +  errorX.getMessage());
		}

	}                                                 
}