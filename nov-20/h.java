import java.util.*;
public class h{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        double ans = 100.0/124*5;
        int n = 4;
        Seg[] arr = new Seg[n];
        Vec[] points = new Vec[n];
        for(int i = 0;i<n;i++){
            Vec a = new Vec(scan.nextDouble(), scan.nextDouble());
            points[i] = a;
        }
        for(int i = 0;i<n;i++){
            Vec to = points[(i+1)%n];
            arr[i] = new Seg(points[i],to);
        }
        Seg south = new Seg(new Vec(-100,-0.5), new Vec(100,-0.5));
        Seg east = new Seg(new Vec(0.5,-100), new Vec(0.5,100));
        Seg north = new Seg(new Vec(-100,0.5), new Vec(100,0.5));
        Seg west = new Seg(new Vec(-0.5,-100), new Vec(-0.5,100));

        Seg[] ours = new Seg[n];
        ours[0] = south;
        ours[1] = east;
        ours[2] = north;
        ours[3] = west;

        double[] coeffs = {1,3,6,4};
        for(int i = 0;i<n;i++){
            ArrayList<Vec> intersects= new ArrayList<>();
            boolean check = false;
            for(int j = 0;j<n;j++){
                Vec curr = points[j];
                //i think this placement is good
                if(ours[i].segIntersection(arr[j])!=null){
                    intersects.add(ours[i].segIntersection(arr[j]));
                    check = true;
                }
                //if(check){
                    boolean good = true;
                    Vec to = arr[j].to;
                    if(i==0){
                        if(to.y> -0.5)good = false;
                    }else if(i==1){
                        if(to.x<0.5)good = false;
                    }else if(i==2){
                        if(to.y<0.5)good = false;
                    }else{
                        if(to.x> -0.5)good = false;
                    }
                    if(good)intersects.add(to);
                    
                //}
            
            }
            //find the area of the polygons
            
            // for(Vec in:intersects){
            //     System.out.println(in.x+" "+in.y);
            // }
            double area = intersects.get(intersects.size()-1).cross(intersects.get(0));
            for(int j = 0;j<intersects.size()-1;j++){
                area+=intersects.get(j).cross(intersects.get(j+1));
            }
            area/=2;
            //System.out.println("RATIO "+(area/25.0));
            //System.out.println(area+" <AREA >COEFS"+coeffs[i]);
            ans+=area*coeffs[i]/24.8;
        }
        System.out.println(ans);
    }
    public static class Vec{
        static final double EPS = 1e-8;
        double x, y;
        public Vec(double x, double y){
            this.x = x;
            this.y = y;
        }
        public Vec sub(Vec o){return new Vec(x-o.x,y-o.y);}
        public Vec scale(double s){return new Vec(x*s,y*s);}
        public Vec add(Vec o){return new Vec(x+o.x,y+o.y);}
        public Vec unit(){return scale(1/mag());}
        public double cross(  Vec o){return x*o.y-y*o.x;}
        public double dot(Vec o){return x*o.x+y*o.y;}
        public double mag2(){return dot(this);}
        public double mag(){return Math.sqrt(mag2());}
        public static boolean eq(double a, double b){return Math.abs(a-b)<EPS;}
    }
    public static class Seg{
        Vec from, to, dir;
        public Seg(Vec from, Vec to){
            this.from= from;
            this.to = to;
            dir = to.sub(from);
        }
        public Vec lineIntersect(Seg o){
            double det = o.dir.x*dir.y-dir.x*o.dir.y;
            if(Vec.eq(det,0))return null;
            double dist = (o.dir.x*(o.from.y-from.y)-
                            o.dir.y*(o.from.x-from.x))/det;
            return from.add(dir.scale(dist));
        }
        public boolean containsPoint(Vec o){
            double distFromLine = dir.unit().cross(o.sub(from));
            if (!Vec.eq(distFromLine, 0))return false;
            return Vec.eq(dir.mag(), from.sub(o).mag()+to.sub(o).mag());
        }
        //check intersections against every side we should only have 2 regardless
        public Vec segIntersection(Seg o){
            Vec intersect = lineIntersect(o);
            if(intersect == null)return null;
            return containsPoint(intersect) &&o.containsPoint(intersect)?intersect:null;
        }
    }
}