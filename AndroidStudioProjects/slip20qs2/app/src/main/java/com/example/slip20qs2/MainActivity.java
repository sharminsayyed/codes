/* Demonstrate Array Adapter using List View to display list of Country. */
package com.example.slip20qs2;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    ListView listview ;
    String country []={"USA","INDIA","CHINA","EUROPE","PAKISTAN","DUBAI","AFRICA","ANTARCTICA","SOUTH KOREA","NORTH KOREA","NEPAL","BANGLADESH"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // connect to the xml file here
        //find view by id
        listview = findViewById(R.id.listview);
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1,country); // add the country to array adapter
        listview.setAdapter(adapter);
        listview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Toast.makeText(MainActivity.this,"Selected "+country[position],Toast.LENGTH_SHORT).show();
            }
        });


    }
}