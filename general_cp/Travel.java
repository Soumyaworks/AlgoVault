package general_cp;

public class Travel
{
    private int regid;
    private String name;
    private String pack;
    private int price;
    boolean flight;
    Travel(int id,String n,String p,int pr,boolean f){
        regid=id;
        name=n;
        pack=p;
        price=pr;
        flight=f;
    }
    

    /**
     * @return int return the regid
     */
    public int getRegid() {
        return regid;
    }

    /**
     * @param regid the regid to set
     */
    public void setRegid(int regid) {
        this.regid = regid;
    }

    /**
     * @return String return the name
     */
    public String getName() {
        return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * @return String return the pack
     */
    public String getPack() {
        return pack;
    }

    /**
     * @param pack the pack to set
     */
    public void setPack(String pack) {
        this.pack = pack;
    }

    /**
     * @return int return the price
     */
    public int getPrice() {
        return price;
    }

    /**
     * @param price the price to set
     */
    public void setPrice(int price) {
        this.price = price;
    }

}
