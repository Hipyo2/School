defmodule InClass.CompanyTest do
  use InClass.DataCase

  alias InClass.Company

  describe "areas" do
    alias InClass.Company.Area

    import InClass.CompanyFixtures

    @invalid_attrs %{name: nil}

    test "list_areas/0 returns all areas" do
      area = area_fixture()
      assert Company.list_areas() == [area]
    end

    test "get_area!/1 returns the area with given id" do
      area = area_fixture()
      assert Company.get_area!(area.id) == area
    end

    test "create_area/1 with valid data creates a area" do
      valid_attrs = %{name: "some name"}

      assert {:ok, %Area{} = area} = Company.create_area(valid_attrs)
      assert area.name == "some name"
    end

    test "create_area/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Company.create_area(@invalid_attrs)
    end

    test "update_area/2 with valid data updates the area" do
      area = area_fixture()
      update_attrs = %{name: "some updated name"}

      assert {:ok, %Area{} = area} = Company.update_area(area, update_attrs)
      assert area.name == "some updated name"
    end

    test "update_area/2 with invalid data returns error changeset" do
      area = area_fixture()
      assert {:error, %Ecto.Changeset{}} = Company.update_area(area, @invalid_attrs)
      assert area == Company.get_area!(area.id)
    end

    test "delete_area/1 deletes the area" do
      area = area_fixture()
      assert {:ok, %Area{}} = Company.delete_area(area)
      assert_raise Ecto.NoResultsError, fn -> Company.get_area!(area.id) end
    end

    test "change_area/1 returns a area changeset" do
      area = area_fixture()
      assert %Ecto.Changeset{} = Company.change_area(area)
    end
  end

  describe "generalareas" do
    alias InClass.Company.Generalarea

    import InClass.CompanyFixtures

    @invalid_attrs %{name: nil}

    test "list_generalareas/0 returns all generalareas" do
      generalarea = generalarea_fixture()
      assert Company.list_generalareas() == [generalarea]
    end

    test "get_generalarea!/1 returns the generalarea with given id" do
      generalarea = generalarea_fixture()
      assert Company.get_generalarea!(generalarea.id) == generalarea
    end

    test "create_generalarea/1 with valid data creates a generalarea" do
      valid_attrs = %{name: "some name"}

      assert {:ok, %Generalarea{} = generalarea} = Company.create_generalarea(valid_attrs)
      assert generalarea.name == "some name"
    end

    test "create_generalarea/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Company.create_generalarea(@invalid_attrs)
    end

    test "update_generalarea/2 with valid data updates the generalarea" do
      generalarea = generalarea_fixture()
      update_attrs = %{name: "some updated name"}

      assert {:ok, %Generalarea{} = generalarea} = Company.update_generalarea(generalarea, update_attrs)
      assert generalarea.name == "some updated name"
    end

    test "update_generalarea/2 with invalid data returns error changeset" do
      generalarea = generalarea_fixture()
      assert {:error, %Ecto.Changeset{}} = Company.update_generalarea(generalarea, @invalid_attrs)
      assert generalarea == Company.get_generalarea!(generalarea.id)
    end

    test "delete_generalarea/1 deletes the generalarea" do
      generalarea = generalarea_fixture()
      assert {:ok, %Generalarea{}} = Company.delete_generalarea(generalarea)
      assert_raise Ecto.NoResultsError, fn -> Company.get_generalarea!(generalarea.id) end
    end

    test "change_generalarea/1 returns a generalarea changeset" do
      generalarea = generalarea_fixture()
      assert %Ecto.Changeset{} = Company.change_generalarea(generalarea)
    end
  end

  describe "developers" do
    alias InClass.Company.Developer

    import InClass.CompanyFixtures

    @invalid_attrs %{email: nil, first_name: nil, last_name: nil}

    test "list_developers/0 returns all developers" do
      developer = developer_fixture()
      assert Company.list_developers() == [developer]
    end

    test "get_developer!/1 returns the developer with given id" do
      developer = developer_fixture()
      assert Company.get_developer!(developer.id) == developer
    end

    test "create_developer/1 with valid data creates a developer" do
      valid_attrs = %{email: "some email", first_name: "some first_name", last_name: "some last_name"}

      assert {:ok, %Developer{} = developer} = Company.create_developer(valid_attrs)
      assert developer.email == "some email"
      assert developer.first_name == "some first_name"
      assert developer.last_name == "some last_name"
    end

    test "create_developer/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Company.create_developer(@invalid_attrs)
    end

    test "update_developer/2 with valid data updates the developer" do
      developer = developer_fixture()
      update_attrs = %{email: "some updated email", first_name: "some updated first_name", last_name: "some updated last_name"}

      assert {:ok, %Developer{} = developer} = Company.update_developer(developer, update_attrs)
      assert developer.email == "some updated email"
      assert developer.first_name == "some updated first_name"
      assert developer.last_name == "some updated last_name"
    end

    test "update_developer/2 with invalid data returns error changeset" do
      developer = developer_fixture()
      assert {:error, %Ecto.Changeset{}} = Company.update_developer(developer, @invalid_attrs)
      assert developer == Company.get_developer!(developer.id)
    end

    test "delete_developer/1 deletes the developer" do
      developer = developer_fixture()
      assert {:ok, %Developer{}} = Company.delete_developer(developer)
      assert_raise Ecto.NoResultsError, fn -> Company.get_developer!(developer.id) end
    end

    test "change_developer/1 returns a developer changeset" do
      developer = developer_fixture()
      assert %Ecto.Changeset{} = Company.change_developer(developer)
    end
  end

  describe "statuses" do
    alias InClass.Company.Status

    import InClass.CompanyFixtures

    @invalid_attrs %{name: nil}

    test "list_statuses/0 returns all statuses" do
      status = status_fixture()
      assert Company.list_statuses() == [status]
    end

    test "get_status!/1 returns the status with given id" do
      status = status_fixture()
      assert Company.get_status!(status.id) == status
    end

    test "create_status/1 with valid data creates a status" do
      valid_attrs = %{name: "some name"}

      assert {:ok, %Status{} = status} = Company.create_status(valid_attrs)
      assert status.name == "some name"
    end

    test "create_status/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Company.create_status(@invalid_attrs)
    end

    test "update_status/2 with valid data updates the status" do
      status = status_fixture()
      update_attrs = %{name: "some updated name"}

      assert {:ok, %Status{} = status} = Company.update_status(status, update_attrs)
      assert status.name == "some updated name"
    end

    test "update_status/2 with invalid data returns error changeset" do
      status = status_fixture()
      assert {:error, %Ecto.Changeset{}} = Company.update_status(status, @invalid_attrs)
      assert status == Company.get_status!(status.id)
    end

    test "delete_status/1 deletes the status" do
      status = status_fixture()
      assert {:ok, %Status{}} = Company.delete_status(status)
      assert_raise Ecto.NoResultsError, fn -> Company.get_status!(status.id) end
    end

    test "change_status/1 returns a status changeset" do
      status = status_fixture()
      assert %Ecto.Changeset{} = Company.change_status(status)
    end
  end

  describe "tasks" do
    alias InClass.Company.Task

    import InClass.CompanyFixtures

    @invalid_attrs %{description: nil, name: nil}

    test "list_tasks/0 returns all tasks" do
      task = task_fixture()
      assert Company.list_tasks() == [task]
    end

    test "get_task!/1 returns the task with given id" do
      task = task_fixture()
      assert Company.get_task!(task.id) == task
    end

    test "create_task/1 with valid data creates a task" do
      valid_attrs = %{description: "some description", name: "some name"}

      assert {:ok, %Task{} = task} = Company.create_task(valid_attrs)
      assert task.description == "some description"
      assert task.name == "some name"
    end

    test "create_task/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Company.create_task(@invalid_attrs)
    end

    test "update_task/2 with valid data updates the task" do
      task = task_fixture()
      update_attrs = %{description: "some updated description", name: "some updated name"}

      assert {:ok, %Task{} = task} = Company.update_task(task, update_attrs)
      assert task.description == "some updated description"
      assert task.name == "some updated name"
    end

    test "update_task/2 with invalid data returns error changeset" do
      task = task_fixture()
      assert {:error, %Ecto.Changeset{}} = Company.update_task(task, @invalid_attrs)
      assert task == Company.get_task!(task.id)
    end

    test "delete_task/1 deletes the task" do
      task = task_fixture()
      assert {:ok, %Task{}} = Company.delete_task(task)
      assert_raise Ecto.NoResultsError, fn -> Company.get_task!(task.id) end
    end

    test "change_task/1 returns a task changeset" do
      task = task_fixture()
      assert %Ecto.Changeset{} = Company.change_task(task)
    end
  end

  describe "assignments" do
    alias InClass.Company.Assignment

    import InClass.CompanyFixtures

    @invalid_attrs %{due_date: nil, name: nil}

    test "list_assignments/0 returns all assignments" do
      assignment = assignment_fixture()
      assert Company.list_assignments() == [assignment]
    end

    test "get_assignment!/1 returns the assignment with given id" do
      assignment = assignment_fixture()
      assert Company.get_assignment!(assignment.id) == assignment
    end

    test "create_assignment/1 with valid data creates a assignment" do
      valid_attrs = %{due_date: "some due_date", name: "some name"}

      assert {:ok, %Assignment{} = assignment} = Company.create_assignment(valid_attrs)
      assert assignment.due_date == "some due_date"
      assert assignment.name == "some name"
    end

    test "create_assignment/1 with invalid data returns error changeset" do
      assert {:error, %Ecto.Changeset{}} = Company.create_assignment(@invalid_attrs)
    end

    test "update_assignment/2 with valid data updates the assignment" do
      assignment = assignment_fixture()
      update_attrs = %{due_date: "some updated due_date", name: "some updated name"}

      assert {:ok, %Assignment{} = assignment} = Company.update_assignment(assignment, update_attrs)
      assert assignment.due_date == "some updated due_date"
      assert assignment.name == "some updated name"
    end

    test "update_assignment/2 with invalid data returns error changeset" do
      assignment = assignment_fixture()
      assert {:error, %Ecto.Changeset{}} = Company.update_assignment(assignment, @invalid_attrs)
      assert assignment == Company.get_assignment!(assignment.id)
    end

    test "delete_assignment/1 deletes the assignment" do
      assignment = assignment_fixture()
      assert {:ok, %Assignment{}} = Company.delete_assignment(assignment)
      assert_raise Ecto.NoResultsError, fn -> Company.get_assignment!(assignment.id) end
    end

    test "change_assignment/1 returns a assignment changeset" do
      assignment = assignment_fixture()
      assert %Ecto.Changeset{} = Company.change_assignment(assignment)
    end
  end
end
