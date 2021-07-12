//
//
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>
#include "Restaurant.h"
#include "MealCourier.h"
#include "Order.h"

using namespace std;
using testing::Eq;

TEST(test_ci2, a_getChain) {
    vector<Restaurant*> restaurants;

    MealCourier meals(restaurants);
    vector<Restaurant*> rests = meals.getChain("MacDonald");
    EXPECT_EQ(rests.size(),0);

    restaurants.push_back(new Restaurant("MacDonald", "Porto"));
    restaurants.push_back(new Restaurant("MacDonald", "Gaia"));
    restaurants.push_back(new Restaurant("Dominos", "Porto"));
    restaurants.push_back(new Restaurant("MacDonald", "Matosinhos"));
    restaurants.push_back(new Restaurant("Dominos", "Maia"));
    restaurants.push_back(new Restaurant("KFC", "Matosinhos"));

    MealCourier fastMeal(restaurants);
    fastMeal.generateCatalog();

    rests = fastMeal.getChain("Dominos");
    EXPECT_EQ(rests.size(),2);

    rests = fastMeal.getChain("KFC");
    EXPECT_EQ(rests.size(),1);

    rests = fastMeal.getChain("PizzaHut");
    EXPECT_EQ(rests.size(),0);
}


TEST(test_ci2, b_addLike) {
    vector<Restaurant*> restaurants;
    auto r1 = new Restaurant("MacDonald", "Porto");
    auto r2 = new Restaurant("MacDonald", "Gaia");
    auto r3 = new Restaurant("MacDonald", "Matosinhos");
    auto r4 = new Restaurant("Dominos", "Porto");
    auto r5 = new Restaurant("Dominos", "Maia");
    auto r6 = new Restaurant("KFC", "Matosinhos");

    restaurants.push_back(r1);
    restaurants.push_back(r2);
    restaurants.push_back(r3);
    restaurants.push_back(r4);
    restaurants.push_back(r5);
    restaurants.push_back(r6);

    MealCourier fastMeal(restaurants);
    fastMeal.generateCatalog();

    EXPECT_EQ(fastMeal.addLike(r1),1);
    EXPECT_EQ(fastMeal.addLike(r2),1);
    EXPECT_EQ(fastMeal.addLike(r2),2);

    auto r7 = new Restaurant("PizzaHut", "Matosinhos");
    EXPECT_EQ(fastMeal.addLike(r7),0);
}


TEST(test_ci2, c_getTotalDueInOrders) {
    Restaurant* r1 = new Restaurant("MacDonald", "Porto");
    Restaurant* r2 = new Restaurant("MacDonald", "Gaia");
    Restaurant* r3 = new Restaurant("MacDonald", "Matosinhos");

    Client* c1 = new Client("Joao", "Porto", 123, 50);
    Client* c2 = new Client("Antonio", "Gaia", 111, 30);
    Client* c3 = new Client("Maria", "Maia", 222, 30);

    Order* o1 = new Order(c1, r1, "Menu1", 5.0);
    Order* o2 = new Order(c2, r2, "Menu2", 7.0);
    Order* o3 = new Order(c3, r3, "Menu3", 4.0);

    vector<Order*> ov1; ov1.push_back(o1);
    vector<Order*> ov2; ov2.push_back(o2);
    vector<Order*> ov3; ov3.push_back(o3);

    vector<Courier> couriers;
    Courier cr1("joao@gmail.com");
    Courier cr2("maria@gmail.com");
    Courier cr3("pedro@gmail.com");

    cr1.setDeliveries(ov1);
    cr2.setDeliveries(ov2);
    cr3.setDeliveries(ov3);

    couriers.push_back(cr1);
    couriers.push_back(cr2);
    couriers.push_back(cr3);

    MealCourier fastMeal;
    EXPECT_NEAR(fastMeal.getTotalDueInOrders(), 0.0, 0.01);
    fastMeal.setCouriers(couriers);
    EXPECT_NEAR(fastMeal.getTotalDueInOrders(), 16.0, 0.01);
}

TEST(test_ci2, d_updateCourierEmail) {
    Restaurant* r1 = new Restaurant("MacDonald", "Porto");
    Restaurant* r2 = new Restaurant("MacDonald", "Gaia");
    Restaurant* r3 = new Restaurant("MacDonald", "Matosinhos");

    Client* c1 = new Client("Joao", "Porto", 123, 50);
    Client* c2 = new Client("Antonio", "Gaia", 111, 30);
    Client* c3 = new Client("Maria", "Maia", 222, 30);

    Order* o1 = new Order(c1, r1, "Menu1", 5.0);
    Order* o2 = new Order(c2, r2, "Menu2", 7.0);
    Order* o3 = new Order(c3, r3, "Menu3", 4.0);

    vector<Order*> ov1; ov1.push_back(o1); ov1.push_back(o2);
    vector<Order*> ov2; ov2.push_back(o3);

    vector<Courier> couriers;
    Courier cr1("joao@gmail.com");
    Courier cr2("maria@gmail.com");
    Courier cr3("pedro@gmail.com");

    cr1.setDeliveries(ov1);
    cr2.setDeliveries(ov2);

    couriers.push_back(cr1);
    couriers.push_back(cr2);
    couriers.push_back(cr3);

    MealCourier fastMeal;
    fastMeal.setCouriers(couriers);
    auto htc = fastMeal.getCouriers();
    EXPECT_EQ(htc.size(), 3);

    fastMeal.updateCourierEmail("ana@gmail.com", "teresa@gmail.com");
    htc = fastMeal.getCouriers();
    EXPECT_EQ(htc.size(), 3);
    EXPECT_EQ( htc.find(Courier("ana@gmail.com")) != htc.end(),  false);

    EXPECT_EQ( htc.find(cr1) != htc.end(),  true);
    EXPECT_EQ( htc.find(cr2) != htc.end(),  true);
    EXPECT_EQ( htc.find(cr3) != htc.end(),  true);

    fastMeal.updateCourierEmail("joao@gmail.com", "feitosa@gmail.com");
    EXPECT_EQ(htc.size(), 3);

    htc = fastMeal.getCouriers();
    auto cit = htc.find(Courier("feitosa@gmail.com"));
    EXPECT_EQ( cit != htc.end(),  true);
    if (cit != htc.end())
        EXPECT_EQ( cit->getDeliveries().size(),  2);
    EXPECT_EQ( htc.find(Courier("joao@gmail.com")) != htc.end(),  false);
}


TEST(test_ci2, e_fireCourier) {
    Restaurant* r1 = new Restaurant("MacDonald", "Porto");
    Restaurant* r2 = new Restaurant("MacDonald", "Gaia");
    Restaurant* r3 = new Restaurant("MacDonald", "Matosinhos");

    Client* c1 = new Client("Joao", "Porto", 123, 50);
    Client* c2 = new Client("Antonio", "Gaia", 111, 30);
    Client* c3 = new Client("Maria", "Maia", 222, 30);

    Order* o1 = new Order(c1, r1, "Menu1", 5.0);
    Order* o2 = new Order(c2, r2, "Menu2", 7.0);
    Order* o3 = new Order(c3, r3, "Menu3", 4.0);

    vector<Order*> ov1; ov1.push_back(o1); ov1.push_back(o2);
    vector<Order*> ov2; ov2.push_back(o3);

    vector<Courier> couriers;
    Courier cr1("joao@gmail.com");
    Courier cr2("maria@gmail.com");
    Courier cr3("pedro@gmail.com");

    cr1.setDeliveries(ov1);
    cr2.setDeliveries(ov2);

    couriers.push_back(cr1);
    couriers.push_back(cr2);
    couriers.push_back(cr3);

    MealCourier fastMeal;
    fastMeal.setCouriers(couriers);

    EXPECT_EQ(fastMeal.getCouriers().size(), 3);
    EXPECT_EQ(fastMeal.fireCourier("miguel@gmail.com"), 0);
    EXPECT_EQ(fastMeal.fireCourier("joao@gmail.com"), 2);

    EXPECT_EQ(fastMeal.getCouriers().size(), 2);
    EXPECT_EQ(fastMeal.fireCourier("joao@gmail.com"), 0);
    EXPECT_EQ(fastMeal.fireCourier("pedro@gmail.com"), 3);

    EXPECT_EQ(fastMeal.getCouriers().size(), 1);
    EXPECT_EQ(fastMeal.fireCourier("maria@gmail.com"), 0);

    EXPECT_EQ(fastMeal.getCouriers().size(), 0);
}


TEST(test_ci2, f_deliverNextOrder) {
    Restaurant* r1 = new Restaurant("MacDonald", "Porto");
    Restaurant* r2 = new Restaurant("MacDonald", "Gaia");
    Restaurant* r3 = new Restaurant("MacDonald", "Matosinhos");

    Client* c1 = new Client("Joao", "Porto", 123, 50);
    Client* c2 = new Client("Antonio", "Gaia", 111, 30);
    Client* c3 = new Client("Maria", "Maia", 222, 30);

    Order o11();
    Order o1(c1, r1, "Menu1", 5.0);
    Order o2(c2, r2, "Menu2", 7.0);
    Order o3(c3, r3, "Menu3", 4.0);

    MealCourier fastMeal;

    EXPECT_THROW(fastMeal.deliverNextOrder(), NoOrderToProcess);

    fastMeal.placeOrder(c3, r1, "Menu1", 5.0);
    fastMeal.placeOrder(c2, r3, "Menu3", 7.0);
    fastMeal.placeOrder(c1, r2, "Menu2", 3.0);

    try {
        Client* cl = fastMeal.deliverNextOrder().getClient();
        EXPECT_EQ(cl!=NULL, true);
        if (cl) EXPECT_EQ(cl->getName(), "Joao");
        cl = fastMeal.deliverNextOrder().getClient();
        EXPECT_EQ(cl!=NULL, true);
        if (cl) EXPECT_EQ(cl->getName(), "Antonio");
        cl = fastMeal.deliverNextOrder().getClient();
        EXPECT_EQ(cl!=NULL, true);
        if (cl) EXPECT_EQ(cl->getName(), "Maria");
    }
    catch(NoOrderToProcess &e) {
        cout << "Exception!" << endl;
    }

    EXPECT_THROW(fastMeal.deliverNextOrder(), NoOrderToProcess);
}


TEST(test_ci2, g_withdrawOrder) {
    Restaurant* r1 = new Restaurant("MacDonald", "Porto");
    Restaurant* r2 = new Restaurant("MacDonald", "Gaia");
    Restaurant* r3 = new Restaurant("MacDonald", "Matosinhos");

    Client* c1 = new Client("Joao", "Porto", 123, 50);
    Client* c2 = new Client("Antonio", "Gaia", 111, 30);
    Client* c3 = new Client("Maria", "Maia", 222, 30);

    Order o1(c1, r1, "Menu1", 5.0);
    Order o2(c2, r2, "Menu2", 7.0);
    Order o3(c3, r3, "Menu3", 4.0);

    MealCourier fastMeal;

    EXPECT_EQ(fastMeal.getOrders().size(), 0);
    EXPECT_THROW(fastMeal.withdrawOrder(o1), NoOrderToProcess);

    fastMeal.placeOrder(c3, r1, "Menu1", 5.0);
    fastMeal.placeOrder(c2, r2, "Menu2", 7.0);
    fastMeal.placeOrder(c1, r2, "Menu3", 3.0);

    try {
        EXPECT_EQ(fastMeal.getOrders().size(), 3);
        EXPECT_EQ(fastMeal.withdrawOrder(o2).getDescription(), "Menu2");
        EXPECT_EQ(fastMeal.getOrders().size(), 2);
    }
    catch(NoOrderToProcess &e) {
        cout << "Exception!" << endl;
    }
}
