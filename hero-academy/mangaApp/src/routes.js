import Home from "./Home";
import AddManga from "./AddManga";
import Mangas from "./Mangas";

var routes = [
{
    path: "/home",
    name: "Home",
    component: Home
},
{
    path: "/mangas",
    name: "Mangas",
    component: Mangas
},
{
    path: "/addmanga",
    name: "AddManga",
    component: AddManga
}

];
export default routes;