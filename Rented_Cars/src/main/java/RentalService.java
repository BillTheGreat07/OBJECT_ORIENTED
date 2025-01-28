import java.util.ArrayList;
import java.util.List;

public class RentalService {
    private final List<Vehicle> vehicles = new ArrayList<>();

    public void addVehicle(Vehicle vehicle) {
        vehicles.add(vehicle);
    }

    public Vehicle findVehicleByLicensePlate(String licensePlate) {
        for (Vehicle vehicle : vehicles) {
            if (vehicle.getLicensePlate().equals(licensePlate)) {
                return vehicle;
            }
        }
        return null;
    }

    public double calculateTotalIncome(int days) {
        double totalIncome = 0;
        for (Vehicle vehicle : vehicles) {
            totalIncome += vehicle.calculateRentalCost(days);
        }
        return totalIncome;
    }
}
