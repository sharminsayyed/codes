package com.example.slip9qs2;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {

    // information to create to database
    private static final String database_name = "companyDb";
    private static final int database_version  =1;

    // information about the table in the database
    private static final String table_name = "company";
    private static final String col_id ="id";
    private static final String col_name ="name";
    private static final String col_phn ="phone";
    private static final String col_address ="address";

    //constructor
    public DatabaseHelper( Context context) {
        super(context,database_name ,null ,database_version );
    }


    // create table in database
    @Override
    public void onCreate(SQLiteDatabase db) {
        String create_table = "CREATE TABLE "+table_name+" ( "
                +col_id+" INTEGER PRIMARY KEY AUTOINCREMENT, "
                +col_name+" TEXT , "
                +col_address+" TEXT , "
                +col_phn+" TEXT ) ";
        db.execSQL(create_table);
    }

    //Called when the database version is changed.
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS "+table_name);  // drop the table if it exits
        onCreate(db); // create again
    }
    public boolean insertComapny(String name ,String address ,String phn){
        SQLiteDatabase db = this.getWritableDatabase(); // get into the write mode to we can insert
        ContentValues val = new ContentValues(); // use this to insert values
        val.put(col_name,name);
        val.put(col_address,address);
        val.put(col_phn,phn);
        long result = db.insert(table_name,null,val); // insert values in the table
        return result != -1;
    }

    public Cursor showCompany(){
        SQLiteDatabase db = this.getReadableDatabase(); // get int the read mode
       return  db.rawQuery("SELECT * FROM " +table_name,null); // get the all data from the table
    }
}
