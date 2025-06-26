/* Create an Android application that creates a custom Alert Dialog containing Friends
Name and onClick of Friend Name Button greet accordingly. */
package com.example.slip5qs2;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import com.google.android.material.bottomappbar.BottomAppBarTopEdgeTreatment;
public class MainActivity extends AppCompatActivity {

    Button btn ;
    String []friends = {"sharmin","ehad","laxmi","jyoti","nafisa","zainab","alice"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //find view by id
        btn = findViewById(R.id.button);
        // on the click of button it show layout with frnd button
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
              showFriendsAlert();
            }
        });

    }
    // on the click of button it show layout with frnds button
    private void showFriendsAlert(){
        AlertDialog.Builder builder = new AlertDialog.Builder(this); // create an alert builder and set title
        builder.setTitle("Select a Friend :");

        // create a layout in which we have all frnds buttons
        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL); // give orientattion
        layout.setPadding(20,20,20,20); // give padding

        // one by one create a button and add to the layout
        for(String friend : friends){
            Button frndbtn = new Button(this); // create a button
            frndbtn.setText(friend); // add frnds name to the button
            frndbtn.setOnClickListener(new View.OnClickListener() {
                @Override
                // on the click of one frnd button greet that frnd in alert box
                public void onClick(View v) {
                    showGreetingAlert(friend);
                }
            });
            layout.addView(frndbtn); // here we have the button to the layout
        }
        builder.setView(layout); // add the laout to the alert box
        builder.setNegativeButton("Cancel",null); //seth the button
        builder.show(); // show the layout

    }

    // create a function to give greeting to the frnd when we click a frnd button
    private void showGreetingAlert(String friend){
        new AlertDialog.Builder(this)
                .setTitle("Greeting ")
                .setMessage("hello "+friend+" ! Long Time no See")
                .setPositiveButton("OK",null)
                .show();
    }

}
