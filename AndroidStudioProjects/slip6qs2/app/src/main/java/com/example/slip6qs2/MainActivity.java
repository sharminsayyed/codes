/* Create an Android Application that Demonstrates ListView and Onclick of List Display the
Toast. */
package com.example.slip6qs2;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect to the xml file
        ListView listView = findViewById(R.id.listview);
        String []fruits={"sunflower","banana","watermelon","muskmelon","guava","cheery","litchi","strawberry","pineapple","apple","manogo","coconut","raspberry","sitafal"};
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1,fruits);
        listView.setAdapter(adapter);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String fruit = fruits[position];
                Toast.makeText(MainActivity.this,"Selected : "+fruit,Toast.LENGTH_SHORT).show();
            }
        });
    }
}