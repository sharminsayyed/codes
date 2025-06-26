/*Create an Android App, it reads the Students Details (Name, Surname, Class, Gender, Hobbies,
Marks) and display the all information in another activity in table format on click of Submit button.
 */
package com.example.slip16qs1;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {
    EditText Name ,Surname,Class,Gender,Hobbies,Marks;
    Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main); // connect the xml file
        // find view by id
        Name = findViewById(R.id.Name);
        Surname = findViewById(R.id.Surname);
        Class = findViewById(R.id.Class);
        Gender = findViewById(R.id.Gender);
        Hobbies = findViewById(R.id.Hobbies);
        Marks = findViewById(R.id.Marks);
        btn = findViewById(R.id.btn);
        // on click of button submit all details and pass to another activity
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // conversions
                String name = Name.getText().toString();
                String surname = Surname.getText().toString();
                String classs = Class.getText().toString();
                String gender = Gender.getText().toString();
                String hobbies = Hobbies.getText().toString();
                String marks = Marks.getText().toString();
                // create intent and pass details
                Intent intent = new Intent (MainActivity.this, result.class);
                intent.putExtra("NAME",name);
                intent.putExtra("SURNAME",surname);
                intent.putExtra("CLASS",classs);
                intent.putExtra("GENDER",gender);
                intent.putExtra("HOBBIES",hobbies);
                intent.putExtra("MARKS",marks);
                startActivity(intent);
            }
        });


    }
}