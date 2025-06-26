package com.example.slip4qs2;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {
    // get data for the database first
    private static final String database_name ="customerDB";
    private static final int database_version=1;
    // get data for the table
    private static final String table_name ="customer";
    private static final String col_id ="id";
    private static final String col_name ="name";
    private static final String col_address = "address";
    private static final String col_phone ="phone";

    // constructor
    public DatabaseHelper( Context context) {
        super(context, database_name, null, database_version);
    }

    // to create table
    @Override
    public void onCreate(SQLiteDatabase db) {
        String create_table=" CREATE TABLE "+table_name+" ( "
                +col_id+" INTEGER PRIMARY KEY AUTOINCREMENT , "
                +col_name+" TEXT , "
                +col_address+" TEXT , "
                +col_phone+" TEXT ) ";
        db.execSQL(create_table);
    }

    //called when we change  database version
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS "+table_name); // drop table
        onCreate(db); //create again
    }

    public boolean insertCustomer(String name ,String address ,String phone){
        SQLiteDatabase db = this.getWritableDatabase();// get the databse in writable mode
        ContentValues val = new ContentValues(); // used to insert values
        val.put(col_name,name);
        val.put(col_address,address);
        val.put(col_phone,phone);
        long result = db.insert(table_name,null,val); // insert in the table with the values
        return result != -1;
    }
    public Cursor showAll(){
        SQLiteDatabase db = this.getReadableDatabase(); // get in the read mode
        return db.rawQuery("SELECT * FROM "+table_name,null);
    }
}
