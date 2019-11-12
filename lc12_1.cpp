class Solution {
public:
    string intToRoman(int num) {	// AC
        string restr;
        while (num >= 1000) {
            restr += "M";
            num -= 1000;
        }
        if(num >= 900) {
            restr += "CM";
            num -= 900;
        }
        while (num >= 500) {
        	restr += "D";
        	num -= 500;
        }
        if(num >= 400) {
        	restr += "CD";
        	num -= 400;
        }
        while (num >= 100) {
        	restr += "C";
        	num -= 100;
        }
        if(num >= 90) {
        	restr += "XC";
        	num -= 90;
        }
        while (num >= 50) {
        	restr += "L";
        	num -= 50;
        }
        if(num >= 40) {
        	restr += "XL";
        	num -= 40;
        }
        while (num >= 10) {
        	restr += "X";
        	num -= 10;
        }
        if(num >= 9) {
        	restr += "IX";
        	num -= 9;
        }
        while (num >= 5) {
        	restr += "V";
        	num -= 5;
        }
        if(num >= 4) {
        	restr += "IV";
        	num -= 4;
        }
        while (num > 0) {
        	restr += "I";
        	num--;
        }
        return restr;
    }
};