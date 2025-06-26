/*
* Create an Android Application to accept two numbers and find power and Average. Display
the result on the next activity using Context Menu.*/
package com.example.slip18qs2;
import android.content.Intent;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {

    EditText num1 ,num2 ;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // connect to xml
        // find view by id
        num1 = findViewById(R.id.number1);
        num2=findViewById(R.id.number2);
        btn = findViewById(R.id.button);
        registerForContextMenu(btn); // regester for context menu
        // on long press of the btn display the context menu
        btn.setOnLongClickListener(new View.OnLongClickListener() {
            @Override
            public boolean onLongClick(View v) {
                openContextMenu(v);
                return true;
            }
        });
    }
    // create a context menu and add the menu and item
    @Override
    public void onCreateContextMenu(ContextMenu menu , View v, ContextMenu.ContextMenuInfo menuifo){
        super.onCreateContextMenu(menu,v,menuifo);
        menu.setHeaderTitle("Select an option :");
        menu.add(0,1,0,"power");
        menu.add(0,2,0,"average");
    }

    // according to option selected from the menu perform operations and send the result to another activity using intent
    @Override
    public boolean onContextItemSelected(MenuItem item){
        int n1 = Integer.parseInt(num1.getText().toString());
        int n2 =Integer.parseInt(num2.getText().toString());
        double result =0;
        if(item.getItemId() == 1){
            result = Math.pow(n1,n2);
        }else{
            result = (n1+n2)/2;
        }
        Intent intent =new Intent(MainActivity.this,result.class);
        intent.putExtra("Result",result);
        startActivity(intent);
        return true; // beacuse we have handled the item selected
    }
}