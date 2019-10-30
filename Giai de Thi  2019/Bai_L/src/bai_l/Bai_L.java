/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bai_l;

import java.util.ArrayList;

/**
 *
 * @author Hoc vien
 */
public class Bai_L {

    public int chiSo = 1;
    public String kq = "";
    
    
    public void ListThuaSo(ArrayList<Integer> listThuaSo, int number)
    {
        for (int i = 0; i < listThuaSo.size(); i++) {
            int j = listThuaSo.size() - i -1;
            if(snt(listThuaSo.get(j)) == true)
            {
                kq += "-S" + chiSo + "-" + listThuaSo.get(i) + "-" + listThuaSo.get(j);
                chiSo++;
            }
            else
            {
                kq += "-S" + chiSo + "-" + listThuaSo.get(i);
                chiSo++;
                ArrayList<Integer> listThuaSoTam = new ArrayList<>();
                listThuaSoTam = thuaSo(listThuaSo.get(j));
                ListThuaSo2(listThuaSoTam, listThuaSo.get(i));
                kq += "-S" + chiSo + "-" + listThuaSo.get(i) + "-" + listThuaSo.get(j);
                chiSo++;
            }   
           
        }  
        kq += "-S" + chiSo + "-" + number;
    }
    
    public void ListThuaSo2(ArrayList<Integer> listThuaSo, int soChu)
    {
        for (int i = 0; i < listThuaSo.size(); i++) {
            int j = listThuaSo.size() - i -1;
            if(snt(listThuaSo.get(j)) == true)
            {
                kq += "-" + listThuaSo.get(i) + "-" + listThuaSo.get(j);
                if(i!=listThuaSo.size()-1)
                {
                    kq += "-S" + chiSo + "-" + soChu;
                    chiSo++;
                }
            }
            else
            {
                ArrayList<Integer> listThuaSoTam = new ArrayList<>();
                listThuaSoTam = thuaSo(listThuaSo.get(j));
                ListThuaSo2(listThuaSoTam, listThuaSo.get(j));
            }   

        }  
    }
    
    public ArrayList<Integer> thuaSo(int number)
    {
        ArrayList<Integer> listThuaSo = new ArrayList<>();
        for(int i=2; i<number; i++)
            if(number % i == 0)
                listThuaSo.add(i);
        
        return listThuaSo;
    }
    
    public boolean snt(int num) 
    {
        if(num < 2)
            return false;
        for(int i=2; i<num; i++)
        {
            if(num % i == 0)
                return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        Bai_L bail = new Bai_L();

        ArrayList<Integer> listThuaSo = new ArrayList<>();
        listThuaSo = bail.thuaSo(24);
        bail.ListThuaSo(listThuaSo, 24);
        System.out.println(bail.kq);
    }
}
