/*Design Following Screens using Table Layout. Display the entered text on next activity*/
package com.example.slip19qs2;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;


public class MainActivity extends AppCompatActivity {

    EditText nm ,cw,gw,h,a,add,phn;
    CheckBox cb;
    Button btn;
    RadioGroup genderg;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);//connect to xml
        //find view by id
        nm=findViewById(R.id.fullname);
        cw=findViewById(R.id.currentw);
        gw=findViewById(R.id.goalw);
        h=findViewById(R.id.height);
        a=findViewById(R.id.age);
        add=findViewById(R.id.address);
        phn=findViewById(R.id.phone);
        genderg=findViewById(R.id.gendergroup);
        cb=findViewById(R.id.checkBox);
        btn=findViewById(R.id.button);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showDetails();
            }
        });

    }
    private void showDetails(){
        String name = nm.getText().toString();
        String cweight = cw.getText().toString();
        String gweight = gw.getText().toString();
        String height = h.getText().toString();
        String age = a.getText().toString();
        String phone = phn.getText().toString();
        String address = add.getText().toString();
        int selectedGenderId = genderg.getCheckedRadioButtonId();
        RadioButton selectedGender = findViewById(selectedGenderId);
        String gender = selectedGender != null ? selectedGender.getText().toString() : "Not Selected";
        if(name.isEmpty() || phone.isEmpty()|| !cb.isChecked()){
            Toast.makeText(MainActivity.this,"please fill all the feilds and accept the terms and conditions ",Toast.LENGTH_SHORT).show();
            return ;
        }
        Intent intent = new Intent(MainActivity.this, result.class);
        intent.putExtra("nm",name);
        intent.putExtra("cw",cweight);
        intent.putExtra("gw",gweight);
        intent.putExtra("h",height);
        intent.putExtra("a",age);
        intent.putExtra("phn",phone);
        intent.putExtra("add",address);
        intent.putExtra("gen",gender);
        startActivity(intent);
    }
}