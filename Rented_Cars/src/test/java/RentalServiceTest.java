import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class RentalServiceTest {

    @Test
    void testCalculateRentalCostForCar() {
        Car carWithAC = new Car("XYZ123", "Toyota Camry", 50, true);
        Car carWithoutAC = new Car("ABC123", "Honda Civic", 45, false);
        assertEquals(550, carWithAC.calculateRentalCost(10), "Car with AC rental cost calculation is incorrect.");
        assertEquals(450, carWithoutAC.calculateRentalCost(10), "Car without AC rental cost calculation is incorrect.");
    }

    @Test
    void testCalculateRentalCostForMotorcycle() {
        Motorcycle largeCCMotorcycle = new Motorcycle("MNO456", "Harley Davidson", 100, 600);
        assertEquals(1200, largeCCMotorcycle.calculateRentalCost(10), "Motorcycle with large engine CC rental cost calculation is incorrect.");
    }

    @Test
    void testFindVehicleByLicensePlate() {
        RentalService service = new RentalService();
        Car car = new Car("XYZ123", "Toyota Camry", 50, true);
        service.addVehicle(car);
        assertNotNull(service.findVehicleByLicensePlate("XYZ123"));
        assertNull(service.findVehicleByLicensePlate("NONEXISTENT"));
    }

    @Test
    void testCalculateTotalIncome() {
        RentalService service = new RentalService();
        service.addVehicle(new Car("XYZ123", "Toyota Camry", 50, true));
        service.addVehicle(new Motorcycle("MNO456", "Harley Davidson", 100, 600));
        assertEquals(1650, service.calculateTotalIncome(10), "Total income calculation is incorrect.");
    }
}
