attribute vec3 pos;

void main(){
    gl_FrontColor = gl_Color;
    gl_Position = vec4(pos.x,pos.y,pos.z, 1.0);
}
