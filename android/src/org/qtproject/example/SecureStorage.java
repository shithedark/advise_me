package org.qtproject.example;

import androidx.security.crypto.EncryptedSharedPreferences;
import androidx.security.crypto.MasterKey;
import android.content.Context;
import android.content.SharedPreferences;

public class SecureStorage {
    MasterKey masterKey;
    SharedPreferences sharedPreferences;
    SharedPreferences.Editor editor;


    int init(Context context){
        try{
            masterKey = new MasterKey.Builder(context)
                 .setKeyScheme(MasterKey.KeyScheme.AES256_GCM)
                 .build();

            sharedPreferences = EncryptedSharedPreferences.create(
                      context,
                      "secret_shared_prefs",
                      masterKey,
                      EncryptedSharedPreferences.PrefKeyEncryptionScheme.AES256_SIV,
                      EncryptedSharedPreferences.PrefValueEncryptionScheme.AES256_GCM
                  );
            editor = sharedPreferences.edit();
                  return 1;
            }catch(Exception e){return -1;}}

    void put(String key, String value){
        editor.putString(key, value);
        editor.commit();}

    String get(String key){
       return sharedPreferences.getString(key, "no data");}




}
