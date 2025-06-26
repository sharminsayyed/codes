/* array adapter using list view to display fruits */
package com.example.slip10qs2;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {

    ListView listview ;
    String []fruits ={ "APPLE","BANANA","BLUEBERRIES","STRAWBERRY","PINEAPPLE","APPLE","GUAVA","DRAGON FRUIT","RASPBERRY","WATERMELON","MUSKMELON","GRAPES","APPLE","POMEGRANATE"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // connect the xml file
        // find view by id
        listview = findViewById(R.id.listview);
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1,fruits);
        listview.setAdapter(adapter);
        listview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String f = fruits[position];
                Toast.makeText(MainActivity.this,"selected "+f,Toast.LENGTH_SHORT).show();
            }
        });

    }
}